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
#define mp make_pair
#define endl '\n'
#define un unsigned
#define ll long long
#define db double
#define se second
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

const int N=5e5+10;
set<pair<int,int> > s;
bool del[N];
int la;

signed main() {
	int q,op,v,cnt=0;
	rd(q);
	la=1;
	while(q--) {
		rd(op);
		if(op==1) {
			++cnt;
			rd(v);
			s.insert(mp(-v,cnt));
		}
		else if(op==2) {
			while(del[la]) ++la;
			printf("%d ", la),del[la]=1,++la;
		}
		else {
			while(del[(*s.begin()).se]) s.erase(s.begin());
			v=(*s.begin()).se;
			printf("%d ", v),del[v]=1,s.erase(s.begin());
		}
	}
	return 0;
}