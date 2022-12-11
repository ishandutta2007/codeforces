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

const int N=2e5+5;
int s[N];

signed main() {
	int T,n,m,a,b,t,c,now,win;
	rd(T);
	while(T--) {
		win=0;
		rd(n,m,a,b);
		Rep(i,1,m) rd(s[i]);
		sort(s+1,s+m+1);
		if(a==b) {
			puts("0"); continue;
		}
		if(a<b) {
			c=b-1,t=b-a-1;
		}
		else {
			c=n-b,t=a-b-1;
		}
		now=t;
		Rep(i,1,m) {
			if(now==0||c-s[i]<1) {
				printf("%d\n", i-1);
				win=1;break;
			}
			now=min(now-1,c-s[i]-1);
		}
		if(!win) printf("%d\n", m);
	}
	return 0;
}