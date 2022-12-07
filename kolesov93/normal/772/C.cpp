#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int gcde(i64 a, i64 b, i64& x, i64& y) {
	if (a == 0) {
		x = 0; 
        y = 1;
		return b;
	}
	i64 x1, y1;
	i64 d = gcde(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
 
bool solve(i64 a, i64 b, i64 c, i64& x0, i64& y0, i64& g) {
	g = gcde(llabs(a), llabs(b), x0, y0);
	if (c % g != 0) {
		return false;
    }
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) {
        x0 *= -1;
    }
	if (b < 0) {
        y0 *= -1;
    }
	return true;
}

int get(int from, int to, int m) {
    i64 x, y, g;
    assert(solve(from, m, to, x, y, g));
    if (x < 0) {    
        return (m - ((-x) % m)) % m;
    }
    return x % m;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);
    
            
    int n, m;
    cin >> n >> m;

    vector<char> was(m);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        was[x] = 1;
    }

    vector< vector<int> > g(m + 1);
    for (int x = 0; x < m; ++x) {
        if (was[x]) {
            continue;
        }
        int gr = gcd(x, m);
        g[gr].push_back(x);
    }

    int ans = 0;
    int bestans = 0;
    vector<int> f(m + 1), bestf(m + 1);
    for (int gi = m; gi >= 1; --gi) {
        f[gi] = 0;
        for (int j = 2; i64(j) * gi <= m; ++j) {
            int gj = gi * j;
            if (f[gj] > f[gi]) {
                f[gi] = f[gj];
                bestf[gi] = gj;
            }
        }
        f[gi] += g[gi].size();
        if (f[gi] > ans) {
            ans = f[gi];
            bestans = gi;
        }
    }

    cout << ans << '\n';
    i64 pref = -1;
    while (ans > 0) {
        int x = bestans;
        for (int y : g[x]) {
            int out;
            if (pref == -1) {
                out = y;
                pref = 1;
            } else {
                out = get(pref, y, m);
            }
            cout << out << ' ';
            pref = (out * pref) % m;
            assert(pref == y);
        }
        ans -= g[x].size();
        bestans = bestf[x];
    }
    cout << '\n';

    return 0;
}