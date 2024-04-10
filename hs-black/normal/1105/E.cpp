#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

#include <map>
map<string, int> mp;
ll g[(1<<20) + 5], f, S[55];
int cm, n, m;

inline ll T(int x) { return 1ll << x; }

inline void GET(ll f) {
	for (int i = 1;i <= m; i++)
		if (f & T(i-1)) S[i] |= f ^ T(i-1);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n; i++) {
		int op; string s; cin >> op;
		if (op == 1) GET(f), f = 0;
		else {
			cin >> s;
			if (!mp[s]) mp[s] = ++cm;
			f |= T(mp[s]-1);
		}
	} GET(f);
	ll all = T(m) - 1, k = m / 2, ak = T(k) - 1;
	for (int i = 1;i <= m; i++) S[i] = all ^ S[i];
	for (int i = 1;i <= ak; i++) {
		ll tmp = ak, sz = 0;
		for (int j = 1;j <= k; j++)
			if (i & T(j-1)) tmp &= S[j], sz++;
		if ((tmp & i) == i) g[i] = sz;
	}
	
	for (int i = 1;i <= ak; i++)
		for (int j = 1;j <= k; j++)
			if (!(i & T(j-1))) Mx(g[i | T(j-1)], g[i]); 
	
	ll p = m - k, ap = T(p) - 1, ans = 0;
	for (ll i = 0;i <= ap; i++) {
		ll tmp = all, sz = 0;
		for (int j = 1;j <= p; j++)
			if (i & T(j-1)) tmp &= S[j+k], sz++;
		if (((tmp >> k) & i) == i) Mx(ans, sz + g[tmp & ak]);
	}
		
	cout << ans << endl;
	return 0;
}