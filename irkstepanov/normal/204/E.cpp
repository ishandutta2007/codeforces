#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct SuffixArray {

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

	int get(int l, int r) {
	    int len = r - l + 1;
	    int k = deg[len];
	    return min(sparse[k][l], sparse[k][l + len - (1 << k)]);
	}

	vector<int> s;
	int n;

	static const int nmax = 200500;
	static const int rmax = 20;
	static const int sigma = 200500;
	
	vector<int> p, c, cnt, pn, cn, lcp, pos, deg;
	vector<vector<int> > sparse;
};

void revive(vector<int>& alive, int& cnt, int x) {
	++alive[x];
	if (alive[x] == 1) {
		++cnt;
	}
}

void kill(vector<int>& alive, int& cnt, int x) {
	--alive[x];
	if (alive[x] == 0) {
		--cnt;
	}
}

const int inf = 1e9;

struct SegmentTree {
	SegmentTree(int n) : n(n) {
		t.assign(4 * n, -inf);
	}

	void upd(int l, int r, int val) {
		inner_upd(1, 0, n - 1, l, r, val);
	}

	int get(int pos) {
		return inner_get(1, 0, n - 1, pos);
	}

	void inner_upd(int v, int tl, int tr, int l, int r, int val) {
		if (tl == l && tr == r) {
			t[v] = max(t[v], val);
			return;
		}
		int tm = (tl + tr) >> 1;
		if (l <= tm) {
			inner_upd(v * 2, tl, tm, l, min(r, tm), val);
		}
		if (r > tm) {
			inner_upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
		}
	}

	int inner_get(int v, int tl, int tr, int pos) {
		if (tl == tr) {
			return t[v];
		}
		int ans = t[v];
		int tm = (tl + tr) >> 1;
		if (pos <= tm) {
			ans = max(ans, inner_get(v * 2, tl, tm, pos));
		} else {
			ans = max(ans, inner_get(v * 2 + 1, tm + 1, tr, pos));
		}
		return ans;
	}

	vector<int> t;
	int n;
};
 
int main() {

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    if (k == 1) {
    	for (int i = 0; i < n; ++i) {
    		ll x = sz(a[i]);
    		cout << x * (x + 1) / 2 << " ";
    	}
    	cout << "\n";
    	return 0;
    }
    if (k > n) {
    	for (int i = 0; i < n; ++i) {
    		cout << "0 ";
    	}
    	cout << "\n";
    	return 0;
    }

    vector<int> s;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < sz(a[i]); ++j) {
    		s.pb(a[i][j] - 'a' + n);
    	}
    	s.pb(i);
    }

    SuffixArray array(s);

    vector<int> id(sz(s), -1);
    vector<int> hlp(sz(s));
    int sum = sz(a[0]);
    for (int i = 0; i < n; ++i) {
    	assert(array.pos[sum] == i);
    	if (i + 1 < n) {
    		sum += sz(a[i + 1]) + 1;
    	}
    }

    sum = 0;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < sz(a[i]); ++j) {
    		int p = array.pos[sum++];
    		hlp[p] = j;
    		id[p] = i;
    	}
    	++sum;
    }

    vector<int> alive(n, 0);
    int cnt = 0;
    int lf = n;
    revive(alive, cnt, id[lf]);
    int rg = n;
    while (cnt < k) {
    	++rg;
    	revive(alive, cnt, id[rg]);
    }

    SegmentTree segtree(sz(s));
    SegmentTree other(sz(s));

    while (true) {
    	int len = array.get(lf, rg - 1);
    	segtree.upd(rg, sz(s) - 1, lf);
    	other.upd(lf, rg, len);
    	//cout << lf << " " << rg << " " << len << endl;
    	kill(alive, cnt, id[lf]);
    	++lf;
    	while (cnt < k && rg + 1 < sz(s)) {
    		++rg;
    		revive(alive, cnt, id[rg]);
    	}
    	if (cnt < k) {
    		break;
    	}
    }

    vector<ll> ans(n);
    for (int i = n; i < sz(s); ++i) {
    	int x = segtree.get(i);
    	int y = other.get(i);
    	if (x != -inf) {
    		x = array.get(x, i - 1);
    	}
    	ans[id[i]] += max(x, y);
    	//cout << i << " " << x << endl;
    	//ans[j] += sz(a[j]) - (hlp[i] + x - 1);
    	//ans[j] += x;
    }

    for (int i = 0; i < n; ++i) {
    	cout << ans[i] << " ";
    }
    cout << "\n";
 
}