#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <queue>
using namespace std;

struct pt {
	long long x, y;

	bool operator< (const pt& other) const {
		// y / x < other.y / other.x
		return y * other.x < other.y * x;
	}
};

int n, k;
pt a[205];

int m;
pt b[205], c;

queue<int> q[205];
vector<int> ine[205], oute[205];

long long det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

void connect(int a, int b) {
	oute[a].push_back(b);
	ine[b].push_back(a);
}

void proceed(int x, int y) {
	while (q[x].size() && det(b[q[x].front()], b[x], b[y]) > 0) {
		proceed(q[x].front(), y);
		q[x].pop();
	}
	connect(x, y);
	q[y].push(x);
}

void visgraph() {
	for (int i=1; i<=m; i++) {
		q[i] = q[0];
		ine[i].clear();
		oute[i].clear();
	}
	for (int i=1; i<m; i++) {
		proceed(i, i+1);
	}
}

long long dp[205][205][55];
long long sol = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i].x >> a[i].y;
	}

	for (int i=1; i<=n; i++) {
		c = a[i];
		m = 0;
		for (int j=1; j<=n; j++) {
			if (j != i && a[j].x >= c.x) {
				m++;
				b[m].x = a[j].x - c.x;
				b[m].y = a[j].y - c.y;
			}
		}

		if (m < k-1) {
			continue;
		}

		sort(b+1, b+m+1);
		visgraph();

		for (int x=1; x<m; x++) {
			for (int y : oute[x]) {
				dp[x][y][1] = det({0, 0}, b[x], b[y]);
			}
		}

		for (int amt=2; amt<=k-2; amt++) {
			for (int y=2; y<m; y++) {
				long long best = 0;

				int ix = 0;

				for (int z : oute[y]) {
					while (ix < (int)ine[y].size() && det(b[ine[y][ix]], b[y], b[z]) > 0) {
						best = max(best, dp[ine[y][ix]][y][amt-1]);
						ix++;
					}
					if (best > 0) {
						dp[y][z][amt] = best + det({0, 0}, b[y], b[z]);
					} else {
						dp[y][z][amt] = 0;
					}
				}
			}
		}

		for (int x=1; x<m; x++) {
			for (int y : oute[x]) {
				sol = max(sol, dp[x][y][k-2]);
			}
		}
	}
	cout << sol / 2 << '.' << (sol % 2 ? "50" : "00");
}