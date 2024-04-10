#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

vector<int> u[500005];
vector<int> m[500005];
int ul[500005], ml[500005];
int n, q;
vector<pair<int,ll> > uu[500005]; int mt[500005];
int wu[500005], wm[500005];
pair<int,ll> sd[500005];
int T;

int gl(int *l, int i) {
	return i == l[i] ? i : l[i] = gl(l, l[i]);
}

ll query(int i) {
	ll res = 0;
	int ct = mt[wm[i]];
	if (ct < sd[i].first) res += sd[i].second;
	const auto &myu = uu[wu[i]];
	int ei = lower_bound(myu.begin(), myu.end(), make_pair(ct,-1ll)) - myu.begin();
	res += myu.back().second - myu[ei-1].second;
	return res;
}

int main() {
	scanf("%d%d", &n, &q);
	FO(i,1,n+1) {
		u[i].push_back(i), m[i].push_back(i);
		ul[i] = ml[i] = i;
		uu[i].emplace_back(-1,0ll);
		wu[i] = wm[i] = i;
	}
	FO(z,0,q) {
		T++;
		char ch; scanf(" %c", &ch);
		if (ch == 'Q') {
			int x; scanf("%d", &x);
			printf("%lld\n", query(x));
		} else if (ch == 'U') {
			int a, b; scanf("%d%d", &a, &b);
			a = gl(ul, a); b = gl(ul, b);
			if (sz(u[a]) > sz(u[b])) {
				swap(a,b);
			}
			// a is small
			ul[a] = b;

			vector<int> mv = u[a];
			vector<ll> oans(sz(mv));
			FO(i,0,sz(mv)) oans[i] = query(mv[i]);
			u[a].clear(); uu[a].clear();
			FO(i,0,sz(mv)) {
				u[b].push_back(mv[i]);
				wu[mv[i]] = b;
				sd[mv[i]] = make_pair(0,0);
			}
			FO(i,0,sz(mv)) {
				ll na = query(mv[i]);
				sd[mv[i]] = make_pair(T++, oans[i]-na);
				assert(query(mv[i]) == oans[i]);
			}
		} else if (ch == 'M') {
			int a, b; scanf("%d%d", &a, &b);
			a = gl(ml, a); b = gl(ml, b);
			if (sz(m[a]) > sz(m[b])) {
				swap(a,b);
			}
			// a is small
			ml[a] = b;

			vector<int> mv = m[a];
			vector<ll> oans(sz(mv));
			FO(i,0,sz(mv)) oans[i] = query(mv[i]);
			m[a].clear();
			FO(i,0,sz(mv)) {
				m[b].push_back(mv[i]);
				wm[mv[i]] = b;
				sd[mv[i]] = make_pair(0,0);
			}
			FO(i,0,sz(mv)) {
				ll na = query(mv[i]);
				sd[mv[i]] = make_pair(T++, oans[i]-na);
				assert(query(mv[i]) == oans[i]);
			}
		} else if (ch == 'A') {
			int x; scanf("%d", &x);
			x = gl(ul, x);
			int s = sz(u[x]);
			uu[x].emplace_back(T++, uu[x].back().second+s);
		} else if (ch == 'Z') {
			int x; scanf("%d", &x);
			x = gl(ml, x);
			mt[x] = T++;
		}
	}
}