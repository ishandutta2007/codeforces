//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx") 
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3f
#define y0 _lxybz_
#define y1 _ljmnzyzhhhoscartxdy_
typedef long double ld;
typedef long long ll;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
#define lo(x) ((x)&(-(x)))
#define trav(a, x) for (auto &a : x)
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
const ld Pi = 4*atan((ld)1);
template<class T> void chmin(T &a,const T&b) { a = min(a, b); }
template<class T> void chmax(T &a,const T&b) { a = max(a, b); }
namespace IO{
template<class T> inline void read(T&ret)
{
	ret=0; int f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	ret*=f;
}
template<class T> inline void prin(const T&ret)
{
	if(!ret){putchar(48);return;} static T o; o=ret;
	if(o<0){putchar('-');o=-o;}
	static int op[25],tt; tt=0;
	while(o){
		op[++tt]=o%10;
		o/=10;
	}
	for(int i=tt;i;--i)putchar(op[i]+48);
}
template<class T> inline void pri_(const T&ret)
{
	prin(ret);putchar(' ');
}
template<class T> inline void priE(const T&ret)
{
	prin(ret);putchar('\n');
}
}
using namespace IO;

#define N 120050
#define MO 
int _u,v,us[N],l[N],r[N],n,a[N],op[N],u,O[N],fa[N];
multiset<int>S;
int fid(int p)
{
	if(p==fa[p])return p;
	return fa[p]=fid(fa[p]);
}
inline void _Sol_()
{
	read(n);
	F(i,1,n)read(a[i]),op[a[i]]=i,fa[i]=i;
	S.clear();F(i,1,n+10)S.insert(0),us[i]=0,O[i]=0;
	F(i,1,n){
		u=op[i];
		if(O[u]!=*--S.end()){
			puts("No");
			return;
		}
		S.erase(S.lower_bound(O[u]));
		l[u]=r[u]=u;
		us[u]=1;
		
		if(!us[u+1]&&u<n){
			O[u+1]=O[u]+1;
			S.insert(O[u+1]);
		} else if(u<n){
			v=fid(u+1);
			fa[u]=v;
			l[v]=u;
			if(r[v]<n){
				S.erase(S.lower_bound(O[r[v]+1]));
				O[r[v]+1]=r[v]-l[v]+1;
				S.insert(O[r[v]+1]);
			}
		}
		
		if(us[u-1]&&u>1){
			v=fid(u-1);
			_u=fid(u);
			fa[_u]=v;
			if(r[_u]<n)S.erase(S.lower_bound(O[r[_u]+1]));
			r[v]=r[_u];
			O[r[_u]+1]=r[v]-l[v]+1;
			if(r[_u]<n)S.insert(O[r[_u]+1]);
		}
	}
	
	puts("Yes");
}

int main()
{
	int T=1; read(T);
	while(T--)_Sol_();
}