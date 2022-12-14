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

#define N 200400
#define MO 
int a[N],u,n,o,v;
set<int>S,P;
vector<int>V;

inline void _Sol_()
{
	read(n); 
	F(i,1,n)read(a[i]);
	
	S.clear(); P.clear();
	F(i,1,n)S.insert(i);
	
	V.clear();
	
	F(i,2,n)if(__gcd(a[i-1],a[i])==1)P.insert(i);
	if(__gcd(a[n],a[1])==1 && n>1) P.insert(1);

	
	u=1;
	while(!P.empty()){
		if(P.upper_bound(u) != P.end()) o=*P.upper_bound(u); else o=*P.begin();
		S.erase(o); P.erase(o); 
		V.push_back(o);
		if(S.size() == 1)break;
		if(S.lower_bound(o)!=S.end()){
			u=*S.lower_bound(o);
		}else u=*S.begin();
		
	//	cerr<<u<<' '<<o<<endl;
		
		P.erase(u);
		if(*S.begin() == u) v=*--S.end(); else v=*--S.lower_bound(u);
		
		if(__gcd(a[u],a[v]) == 1) {
			P.insert(u);
		}
	}
	
	if(S.size()==1 && a[*S.begin()]==1)V.push_back(*S.begin());	
	pri_(V.size());
	for(auto u:V)pri_(u);puts("");
}

int main()
{
	int T=1; read(T);
	while(T--)_Sol_();
}
/*
1
2
1 2
6
1 2 4 2 4 2
5
5 9 2 10 15
*/