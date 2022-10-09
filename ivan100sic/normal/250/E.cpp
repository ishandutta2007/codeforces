// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

tuple<int, int, ll> solve(string a, const string& b, int gaze, int x, int m) {
	int obstacleLeft = x;
	int obstacleRight = x;

	auto extendLeft = [&]() {
		while (a[obstacleLeft] == '.') obstacleLeft--;
	};

	auto extendRight = [&]() {
		while (a[obstacleRight] == '.') obstacleRight++;
	};

	extendLeft();
	extendRight();

	vector<int> rightPit(m, 1e9), leftPit(m, -1e9);
	for (int i=0; i<m; i++) {
		if (i > 0) {
			leftPit[i] = leftPit[i-1];
		}
		if (b[i] == '.') {
			leftPit[i] = i;
		}
	}

	for (int i=m-1; i>=0; i--) {
		if (i+1 < m) {
			rightPit[i] = rightPit[i+1];
		}
		if (b[i] == '.') {
			rightPit[i] = i;
		}
	}

	ll t = 0;
	int bounce = 0;

	// sim
	while (bounce < 4) {
		if (b[x] == '.') {
			// propadni
			return {gaze, x, t+1};
		}
		
		if (gaze == 1) {
			if (a[x+1] == '.') {
				// fast forward
				if (rightPit[x] < obstacleRight) {
					return {gaze, rightPit[x], t + rightPit[x] - x + 1};
				} else {
					int d = (obstacleRight - 1) - x;
					t += d;
					x += d;
				}
			} else if (a[x+1] == '+') {
				// brick wall
				a[x+1] = '.';
				extendRight();
				gaze = -1;
				t += 1;
				bounce = 0;
			} else {
				gaze = -1;
				t += 1;
				bounce++;
			}
		} else {
			if (a[x-1] == '.') {
				if (leftPit[x] > obstacleLeft) {
					return {gaze, leftPit[x], t + x - leftPit[x] + 1};
				} else {
					int d = x - (obstacleLeft + 1);
					t += d;
					x -= d;
				}
			} else if (a[x-1] == '+') {
				a[x-1] = '.';
				extendLeft();
				gaze = 1;
				t += 1;
				bounce = 0;
			} else {
				gaze = 1;
				t += 1;
				bounce++;
			}
		}
	}

	return {-1, -1, -1};
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, m;
	cin >> n >> m;
	m += 2;
	vector<string> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i] = string("#") + a[i] + "#";
	}

	int x = 1, gaze = 1;
	ll tot = 0;
	for (int i=0; i<n-1; i++) {
		auto [gaze1, x1, t] = solve(a[i], a[i+1], gaze, x, m);
		if (x1 == -1) {
			cout << "Never\n";
			return 0;
		}
		x = x1;
		tot += t;
		gaze = gaze1;
	}

	cout << tot << '\n';
}