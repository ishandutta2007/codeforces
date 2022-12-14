#pragma GCC optimize("Ofast")
#pragma GCC target("avx") 
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

#define M 200050
#define N 610
#define MO 
#define D 1000
int qq,uu,vv,_l,ii,i,q,n,m,u[M],v[M],w[M],_u,_v,_w,Ans,_q,fl,Vi[M];
long long di[N][N];
struct Q{
	int u, v, l;
	bool operator < (const Q&a)const{
		return l>a.l;
	}
}A[M];
struct E{
	int u, w, id;
};
vector<E>G[N];
vector<int>mp[N][N];
inline void _Sol_()
{
	read(n); read(m);
	
	F(i,1,n)
	F(j,1,n) di[i][j] = 1e17;
	
	F(i,1,n) di[i][i]=0;
	
	F(i,1,m){
		read(u[i]); read(v[i]); read(w[i]);
		G[u[i]].push_back((E){v[i],w[i],i});
		G[v[i]].push_back((E){u[i],w[i],i});
		di[u[i]][v[i]]=di[v[i]][u[i]]=w[i];
	}
	
	F(k,1,n)
	F(i,1,n)
	F(j,1,n) di[i][j] = min(di[i][j],di[i][k]+di[k][j]);
	
	read(qq); 
	F(i,1,qq){
		read(uu);read(vv);read(_l);
		if(di[uu][vv]>_l)continue;
		A[++q].u=uu,A[q].v=vv,A[q].l=_l;
		mp[uu][vv].push_back(_l);
		mp[vv][uu].push_back(_l);
	}
	if(!q){
		puts("0");return;
	}
	
	F(u,1,n)
	F(y,1,n){
		long long ma=-1e9;
		F(v,1,n){
			
			for(auto h:mp[u][v])chmax(ma,(ll)h-di[y][v]);
			
		}
		for(auto h:G[y]){
				if(di[u][h.u]+h.w <= ma)Vi[h.id]=1;
			}
	}
	
	F(i,1,m) Ans += Vi[i];
	priE(Ans);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}