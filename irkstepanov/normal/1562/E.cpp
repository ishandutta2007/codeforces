#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct SuffixArray {
	// terminates with $

	SuffixArray(const vector<int>& s) : s(s) {
		p.resize(nmax);
		c.resize(nmax);
		cnt.assign(nmax, 0);
		pn.resize(nmax);
		cn.resize(nmax);
		lcp.resize(nmax);
		pos.resize(nmax);
		deg.resize(nmax);
		sparse = vector<vector<int> >(rmax, vector<int>(nmax));
	    n = sz(s);
	    for (int i = 0; i < sz(s); ++i) {
	        ++cnt[s[i]];
	    }
	    for (int i = 1; i < sigma; ++i) {
	        cnt[i] += cnt[i - 1];
	    }
	    for (int i = n - 1; i >= 0; --i) {
	        p[--cnt[s[i]]] = i;
	    }
	    c[p[0]] = 0;
	    int curr = 0;
	    for (int i = 1; i < n; ++i) {
	        if (s[p[i]] != s[p[i - 1]]) {
	            ++curr;
	        }
	        c[p[i]] = curr;
	    }
	    ++curr;
	    int len = 2;
	    while (true) {
	        for (int i = 0; i < n; ++i) {
	            pn[i] = p[i] - (len >> 1);
	            if (pn[i] < 0) {
	                pn[i] += n;
	            }
	        }
	        cnt.assign(curr, 0);
	        for (int i = 0; i < n; ++i) {
	            ++cnt[c[i]];
	        }
	        for (int i = 1; i < curr; ++i) {
	            cnt[i] += cnt[i - 1];
	        }
	        for (int i = n - 1; i >= 0; --i) {
	            p[--cnt[c[pn[i]]]] = pn[i];
	        }
	        cn[p[0]] = 0;
	        curr = 0;
	        for (int i = 1; i < n; ++i) {
	            if (c[p[i]] != c[p[i - 1]]) {
	                ++curr;
	            } else {
	                int x = p[i] + (len >> 1), y = p[i - 1] + (len >> 1);
	                if (x >= n) {
	                    x -= n;
	                }
	                if (y >= n) {
	                    y -= n;
	                }
	                if (c[x] != c[y]) {
	                    ++curr;
	                }
	            }
	            cn[p[i]] = curr;
	        }
	        ++curr;
	        c = cn;
	        if (len >= n) {
	            break;
	        }
	        len <<= 1;
	    }

	    deg[1] = 0;
	    for (int i = 2; i < nmax; ++i) {
	        deg[i] = deg[i - 1];
	        if (!(i & (i - 1))) {
	            ++deg[i];
	        }
	    }

	    for (int i = 0; i < n; ++i) {
	        pos[p[i]] = i;
	    }

	    curr = 0;
	    for (int i = 0; i < n; ++i) {
	        curr = max(curr - 1, 0);
	        if (pos[i] + 1 == n) {
	            curr = 0;
	            continue;
	        }
	        int j = p[pos[i] + 1];
	        while (i + curr < n && j + curr < n && s[i + curr] == s[j + curr]) {
	            ++curr;
	        }
	        lcp[pos[i]] = curr;
	    }

	    for (int i = 0; i < n; ++i) {
	        sparse[0][i] = lcp[i];
	    }
	    for (int r = 0; r + 1 < rmax; ++r) {
	        for (int i = 0; i < n; ++i) {
	            int j = min(n - 1, i + (1 << r));
	            sparse[r + 1][i] = min(sparse[r][i], sparse[r][j]);
	        }
	    }
	}

	int get(int l, int r) const {
	    int len = r - l + 1;
	    int k = deg[len];
	    return min(sparse[k][l], sparse[k][l + len - (1 << k)]);
	}

	int LCP(int i, int j) const {
		if (i == j) {
			return n - i;
		}
		int l = pos[i], r = pos[j];
		if (l > r) {
			swap(l, r);
		}
		return get(l, r - 1);
	}

	vector<int> s;
	int n;

	static const int nmax = 5050;
	static const int rmax = 15;
	static const int sigma = 5050;
	
	vector<int> p, c, cnt, pn, cn, lcp, pos, deg;
	vector<vector<int> > sparse;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tt;
    cin >> tt;

    while (tt--) {
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;
    	vector<int> a(n + 1);
    	for (int i = 0; i < n; ++i) {
    		a[i] = (s[i] - 'a') + 1;
    	}
    	a[n] = 0;

    	SuffixArray sa(a);

    	vector<ll> dp(n);
    	dp[0] = n;
    	for (int i = 1; i < n; ++i) {
    		dp[i] = n - i;
    		for (int j = 0; j < i; ++j) {
    			if (sa.pos[i] < sa.pos[j]) {
    				continue;
    			}

    			int r = sa.LCP(i, j);

    			//cout << i << " " << j << " " << r << endl;
    			dp[i] = max(dp[i], dp[j] + n - i - r);

    		}

    	}

    	ll ans = 0;
    	for (int i = 0; i < n; ++i) {
    		ans = max(ans, dp[i]);
    	}
    	cout << ans << "\n";
    }

}