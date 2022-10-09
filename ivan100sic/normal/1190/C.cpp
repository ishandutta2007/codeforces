#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int n = 11, k = 6;
int winner[4096][4096];

vector<int> moves(int mask) {
	vector<int> a;
	int q = (1<<k)-1;
	for (int i=0; i<=n-k; i++) {
		a.push_back(mask | (q << i));
		a.push_back(~(~mask | (q << i)));
	}
	return a;
}

int grab(int mask) {
	int l0=123123, l1=123123;
	int h0=-1, h1=-1;
	for (int i=0; i<n; i++) {
		if (mask & (1 << i)) {
			l0 = min(l0, i);
			h0 = max(h0, i);
		} else {
			l1 = min(l1, i);
			h1 = max(h1, i);
		}
	}
	return max(0, min(h1-l1+1, h0-l0+1));
}

void brute() {
	winner[0][0] = 2;
	winner[0][(1<<n)-1] = 2;
	for (int i=1; i<(1<<n); i++) {
		for (int j=0; j<(1<<n); j++) {
			if (j == 0 || j == (1<<n)-1) {
				winner[i][j] = 2;
				continue;
			}
			int c[3] = {0, 0, 0};
			for (int x : moves(j)) {
				c[winner[i-1][x]]++;
			}

			if (c[2] > 0) {
				winner[i][j] = 1;
			} else if (c[0] == 0 && c[2] == 0) {
				winner[i][j] = 2;
			} else {
				winner[i][j] = 0;
			}
		}
	}

	auto w = winner[(1<<n)-1];
	for (int j=0; j<3; j++) {
		for (int i=0; i<(1<<n); i++) {
			if (w[i] == j)
				cout << bitset<n>(i) << ' ' << w[i] << '\n';
		}
	}
	
	for (int i=0; i<(1<<n); i++) {
		if (w[i] == 1 && grab(i) > k) {
			cerr << "hipoteza 1 nije tacna\n";
		}
	}
}

int grab(string s) {
	int n = s.size();
	int l0=123123, l1=123123;
	int h0=-1, h1=-1;
	for (int i=0; i<n; i++) {
		if (s[i] == '0') {
			l0 = min(l0, i);
			h0 = max(h0, i);
		} else {
			l1 = min(l1, i);
			h1 = max(h1, i);
		}
	}
	return max(0, min(h1-l1+1, h0-l0+1));
}

int solve(int n, int k, string s) {
	if (s[0] == '1')
		for (int i=0; i<n; i++)
			s[i] ^= 1;

	if (grab(s) == 0) {
		return 1;
	} else if (grab(s) <= k) {
		return 4;
	} else {
		if (2*k >= n) {
			int t = n-k-1;
			if (s.substr(0, t) == string(t, '0') && s[t] == '1' &&
				s.substr(n-t) == string(t, '1') && s[n-t-1] == '0')
			{
				return 8;
			} else {
				return 3;
			}
		} else {
			return 0;
		}
	}
}

string names[3] = {"once again", "tokitsukaze", "quailty"};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// brute();
	// return 0;

	int n, k;
	string s;
	cin >> n >> k >> s;

	int t = solve(n, k, s);
	cerr << t << '\n';
	cout << names[t%3] << '\n';
}