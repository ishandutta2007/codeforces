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
template<class T> void chmax(T &a,const T&b) { a = min(a, b); }
template<class T> void chmin(T &a,const T&b) { a = max(a, b); }
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

#define N 200500
#define MO 
int a[N],b[N],c[N],A,B,C,u;
set<int>Sa,Sb,Sc;
ll Ans;
inline ll q(ll a, ll b, ll c)
{
	return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);
}
inline void _Sol_()
{
	read(A);read(B);read(C);
	F(i,1,A)read(a[i]);
	F(i,1,B)read(b[i]);
	F(i,1,C)read(c[i]);
	
	Ans=q(a[1],b[1],c[1]);
	
	Sa.clear();
	F(i,1,A)Sa.insert(a[i]);
	Sb.clear();
	F(i,1,B)Sb.insert(b[i]);
	Sc.clear();
	F(i,1,C)Sc.insert(c[i]);
	
	F(i,1,A){
		u=a[i];
		auto it=Sb.lower_bound(u);
		auto it2=Sc.lower_bound(u+1);
		if(it!=Sb.end()&&it2!=Sc.begin()){
			--it2;
			chmax(Ans,q(*it2,u,*it));
		}
		it=Sb.lower_bound(u+1);
		it2=Sc.lower_bound(u);
		if(it!=Sb.begin()&&it2!=Sc.end()){
			--it;
			chmax(Ans,q(*it,u,*it2));
		}
	}
	
	F(i,1,B){
		u=b[i];
		auto it=Sa.lower_bound(u);
		auto it2=Sc.lower_bound(u+1);
		if(it!=Sa.end()&&it2!=Sc.begin()){
			--it2;
			chmax(Ans,q(*it2,u,*it));
		}
		it=Sa.lower_bound(u+1);
		it2=Sc.lower_bound(u);
		if(it!=Sa.begin()&&it2!=Sc.end()){
			--it;
			chmax(Ans,q(*it,u,*it2));
		}
	}
	
	F(i,1,C){
		u=c[i];
		auto it=Sb.lower_bound(u);
		auto it2=Sa.lower_bound(u+1);
		if(it!=Sb.end()&&it2!=Sa.begin()){
			--it2;
			chmax(Ans,q(*it2,u,*it));
		}
		it=Sb.lower_bound(u+1);
		it2=Sa.lower_bound(u);
		if(it!=Sb.begin()&&it2!=Sa.end()){
			--it;
			chmax(Ans,q(*it,u,*it2));
		}
	}
	
	priE(Ans);
}

int main()
{
	int T=1; read(T);
	while(T--)_Sol_();
}
/*
1
2 2 3
7 8
6 3
3 1 4
*/