#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int n, m, p;
vector<int> x, y;

string ans = "";
const int nmax = 20050;
int dp[2][nmax];

int get(int i, int j) {
	int ans = x[i] + y[j];
	if (ans >= p) {
		ans -= p;
	}
	return ans;
}

int res[nmax];

void f(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		while (y1 != y2) {
			ans += "S";
			++y1;
		}
		return;
	}
	if (y1 == y2) {
		while (x1 != x2) {
			ans += "C";
			++x1;
		}
		return;
	}
	int mid = (x1 + y1 + x2 + y2) / 2;
	memset(dp[0], -1, sizeof(dp[0]));
	dp[0][0] = get(x1, y1);
	int ptr = 0;
	for (int sum = x1 + y1 + 1; sum <= mid; ++sum) {
		memset(dp[ptr ^ 1], -1, sizeof(dp[ptr]));
		int rg = x2, lf = x1;
		rg = min(rg, sum - y1);
		lf = max(lf, sum - y2);
		for (int x = lf; x <= rg; ++x) {
			int y = sum - x;
			int g = get(x, y);
			int add = 0;
			if (x - 1 >= x1) {
				add = max(add, dp[ptr][(x - 1) - x1]);
			}
			if (y - 1 >= y1) {
				add = max(add, dp[ptr][x - x1]);
			}
			dp[ptr ^ 1][x - x1] = g + add;
		}
		ptr ^= 1;
	}

	memcpy(res, dp[ptr], sizeof(dp[ptr]));

	memset(dp[0], -1, sizeof(dp[0]));
	dp[0][x2 - x1] = get(x2, y2);
	ptr = 0;
	for (int sum = x2 + y2 - 1; sum >= mid; --sum) {
		memset(dp[ptr ^ 1], -1, sizeof(dp[ptr]));
		int rg = x2, lf = x1;
		rg = min(rg, sum - y1);
		lf = max(lf, sum - y2);
		for (int x = lf; x <= rg; ++x) {
			int y = sum - x;
			int g = get(x, y);
			int add = 0;
			if (x + 1 <= x2) {
				add = max(add, dp[ptr][(x + 1) - x1]);
			}
			if (y + 1 <= y2) {
				add = max(add, dp[ptr][x - x1]);
			}
			dp[ptr ^ 1][x - x1] = g + add;
		}
		ptr ^= 1;
	}

	int rg = x2, lf = x1;
	rg = min(rg, mid - y1);
	lf = max(lf, mid - y2);
	int opt = -1;
	int pos;
	for (int x = lf; x <= rg; ++x) {
		int y = mid - x;
		int val = res[x - x1] + dp[ptr][x - x1] - get(x, y);
		if (val > opt) {
			opt = val;
			pos = x;
		}
	}
	f(x1, y1, pos, mid - pos);
	f(pos, mid - pos, x2, y2);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    cin >> n >> m >> p;
    x.resize(n);
    y.resize(m);
    for (int i = 0; i < n; ++i) {
    	cin >> x[i];
    	x[i] %= p;
    }
    for (int i = 0; i < m; ++i) {
    	cin >> y[i];
    	y[i] %= p;
    }

    f(0, 0, n - 1, m - 1);
    int cost = 0;
    int x = 0, y = 0;
    cost += get(x, y);
    for (int i = 0; i < sz(ans); ++i) {
    	if (ans[i] == 'S') {
    		++y;
    	} else {
    		++x;
    	}
    	cost += get(x, y);
    }
    cout << cost << "\n";
    cout << ans << "\n";

}