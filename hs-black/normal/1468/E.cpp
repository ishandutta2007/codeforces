#include <bits/stdc++.h>
using namespace std;
#define clr(a) memset(a, 0, sizeof(a))
#define full(a) memset(a, 0x3f, sizeof(a))
#define mset(a, b) memset(a, b, sizeof(a))
#define cpy(a,b) memcpy(a, b, sizeof(a))
#define fornext(x, i) for(int i = hd[x], y = ver[i]; i; i = nxt[i], y = ver[i])
#define Rep(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define dRep(i, a, b) for(int i = (int)(a); i >= (int)(b); --i)
#define IOset(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout);
#define pb push_back
#define It iterator
#define endl '\n'
#define int ll
#define un unsigned
#define ll long long
#define db double
#define rept cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
#define dbg cout<<"c "
#define dbug(x) cerr << #x " = " << (x) << endl
template<typename _T> inline void _prt(_T _d) { cerr << _d << ' '; }
template <typename _T, typename ...Args> inline void _prt(_T _d, Args ..._a) { _prt(_d), _prt(_a...); }
template <typename _T, typename ...Args> inline void prt(_T _d, Args ..._a) { _prt(_d), _prt(_a...), cerr<<endl; }
template <typename _T, typename ...Args> inline void prt(_T _d) { cerr << _d <<endl; }
template<typename _T> inline void rd(_T &_d) {
	signed _f; char _c; _f = 1,_d = 0; while (_c = getchar(), !isdigit(_c)) if(_c=='-') _f=-1;
	while (isdigit(_c)) _d = _d * 10 + _c - '0', _c = getchar();
	_d=_f*_d;
}
template <typename _T, typename ...Args> inline void rd(_T &_d, Args &..._a) { rd(_d); rd(_a...); }

// const int N=

signed main() {
	int T,a[5];
	rd(T);
	int ans=0;
	while(T--) {
		Rep(i,1,4) rd(a[i]);
		ans=0;
		ans=max(ans,min(a[1],a[2])*min(a[3],a[4]));
		ans=max(ans,min(a[1],a[3])*min(a[2],a[4]));
		ans=max(ans,min(a[1],a[4])*min(a[2],a[3]));
		cout<<ans<<endl;
	}
	return 0;
}