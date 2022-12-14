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

#define N 1003
#define MO 
int fl,u,v,n,m,t,qn,a[N][N],di[N][N],D[N][N],Vi[N][N];
ll p;
char s[N];
struct P {
	int i,j;
}q[N*N];

int ch(int u, int v)
{
	if(u>1&&a[u-1][v]==a[u][v])return 1;
	if(u<n&&a[u+1][v]==a[u][v])return 1;
	if(v>1&&a[u][v-1]==a[u][v])return 1;
	if(v<m&&a[u][v+1]==a[u][v])return 1;
	return 0;
}

inline void _Sol_()
{
	read(n);read(m);read(t);
	F(i,1,n){
		scanf("%s",s+1);
		F(j,1,m)a[i][j]=s[j]=='1';
	}
	F(i,1,n)
	F(j,1,m){
		if(ch(i,j))q[++qn]=(P){i,j},Vi[i][j]=1,di[i][j]=0;
	}
	if(!qn)fl=1;
	F(q1,1,qn){
		u=q[q1].i; v=q[q1].j;
		if(u>1&&!Vi[u-1][v]){
			Vi[u-1][v]=1;
			di[u-1][v]=di[u][v]+1;
			q[++qn]=(P){u-1,v};
		}
		if(u<n&&!Vi[u+1][v]){
			Vi[u+1][v]=1;
			di[u+1][v]=di[u][v]+1;
			q[++qn]=(P){u+1,v};
		}
		if(v>1&&!Vi[u][v-1]){
			Vi[u][v-1]=1;
			di[u][v-1]=di[u][v]+1;
			q[++qn]=(P){u,v-1};
		}
		if(v<m&&!Vi[u][v+1]){
			Vi[u][v+1]=1;
			di[u][v+1]=di[u][v]+1;
			q[++qn]=(P){u,v+1};
		}
	}
	
	while(t--){
		read(u);read(v);read(p);
		if(fl){
			priE(a[u][v]);continue;
		}
		if(p<=di[u][v]){
			priE(a[u][v]);continue;
		}
		p-=di[u][v];
		p%=2;
		priE(a[u][v]^p);
	}
	
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}