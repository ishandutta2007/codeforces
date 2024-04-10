#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fi first
#define se second
#define SZ(x) ((int)(x).size())

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template<typename T> inline void ckmax(T& x, T y) { x = (y > x ? y : x); }
template<typename T> inline void ckmin(T& x, T y) { x = (y < x ? y : x); }

const int MAXM = 1e5;

int n, m;
pii p[MAXM + 5];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> p[i].fi >> p[i].se;
	}
	sort(p + 1, p + m + 1);
	m = unique(p + 1, p + m + 1) - (p + 1);
	
	vector<pii> seg;
	seg.pb(mk(1, 1));
	int lst = 0;
	for (int i = 1; i <= m; ++i) {
		int j = i;
		while (j + 1 <= m && p[j + 1].fi == p[i].fi)
			++j;
		
		if (!SZ(seg)) {
			cout << -1 << endl;
			return 0;
		}
		if (p[i].fi > lst + 1) {
			pii tmp = mk(seg[0].fi, n);
			vector<pii>().swap(seg);
			seg.pb(tmp);
		}
		
		int pre = 0;
		vector<pii> newseg;
		for (int k = i; k <= j; ++k) {
			if (pre + 1 == p[k].se) {
				pre = p[k].se;
				continue;
			}
			// [pre + 1, p[k].se - 1]
			int t = lob(seg.begin(), seg.end(), mk(pre + 1, 0)) - seg.begin();
			
			if (t != 0 && seg[t - 1].se >= pre + 1) {
				newseg.pb(mk(pre + 1, p[k].se - 1));
			} else if (t != SZ(seg) && seg[t].fi <= p[k].se - 1) {
				newseg.pb(mk(seg[t].fi, p[k].se - 1));
			}
			pre = p[k].se;
		}
		if (pre != n) {
			// [pre + 1, n]
			int t = lob(seg.begin(), seg.end(), mk(pre + 1, 0)) - seg.begin();
			
			if (t != 0 && seg[t - 1].se >= pre + 1) {
				newseg.pb(mk(pre + 1, n));
			} else if (t != SZ(seg) && seg[t].fi <= n) {
				newseg.pb(mk(seg[t].fi, n));
			}
		}
		
		// for (int k = 0; k < SZ(newseg); ++k) {
		// 	cerr << "[" << newseg[k].fi << "," << newseg[k].se << "]" << " \n"[k == SZ(newseg) - 1];
		// }
		
		lst = p[i].fi;
		i = j;
		seg = newseg;
	}
	if (!SZ(seg)) {
		cout << -1 << endl;
		return 0;
	}
	if (lst != n) {
		pii tmp = mk(seg[0].fi, n);
		vector<pii>().swap(seg);
		seg.pb(tmp);
	}
	for (int i = 0; i < SZ(seg); ++i) {
		if (seg[i].fi <= n && seg[i].se >= n) {
			cout << n * 2 - 2 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}