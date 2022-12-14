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
struct node{
	int u, w;
	bool operator < (const node&a)const{
		return w<a.w;
	}
};
vector<node>G[N];
struct W{
	int d,w;
}st[N];
int q[10][10],tt,d[N],u,v,w,h[10],A[10][10][10][10],Ans,n,m,k,P[N][10][10];
void dfs(int p)
{
	if(p>k){
		F(i,1,k){
			F(j,i,k)if(A[i][h[i]][j][h[j]])return;
		}
		int hh=0;
		F(i,1,k)hh+=q[i][h[i]];
		if(hh!=n)return;
		++Ans;
		
		//F(i,1,k)cerr<<h[i]<<' ';cerr<<endl;
		
		return;
	}
	F(i,1,p){	
		h[p]=i;
		dfs(p+1);
	}
}

inline void _Sol_()
{
	read(n);read(m);read(k);
	F(i,1,m){
		read(u);read(v);read(w);
		G[u].push_back((node){v,w});
	}
	F(i,1,n)sort(G[i].begin(),G[i].end()),d[i]=G[i].size();
//	pr[0]=0; F(i,1,k)pr[i]=pr[i-1]+i;
	F(i,1,n){
		F2(j,0,d[i]){
	//		f[i][j+1]=G[i][j].u;
			if(!P[G[i][j].u][d[i]][j+1])P[G[i][j].u][d[i]][j+1]=1;
			else A[d[i]][j+1][d[i]][j+1]=1;
			q[d[i]][j+1]++;
		}
	}
//	op[0]=1; F(i,1,k)op[i]=op[i-1]*i;
	
	F(i,1,n){
		tt=0;
		F(j,1,k)
		F(l,1,j)if(P[i][j][l]){
			st[++tt]=(W){j,l};
		}
		
	//	if(tt==1){
	//		if(H[st[1]])
	//	}
		
		F(i,1,tt)
		F(j,i+1,tt){
			A[st[i].d][st[i].w][st[j].d][st[j].w]=1;
		}
	}
	
	dfs(1);
	priE(Ans);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}