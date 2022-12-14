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

#define N 3005

//#define N 100

#define MO 998244353 
#define MO1 998244353
#define MO2 20001111
#define Ba1 37
#define Ba2 101

unordered_map<int,unordered_map<int,int>>mp[100][100];
char s[N],t[N];
int n,m,g1[N],h1[N],g2[N],h2[N],op[N],op1[N],op2[N],A[N][30],B[N][30];
int g[N][N];
int com(int l, int r, int a, int b)
{
	int c=(h1[r]-(ll)h1[l-1]*op1[r-l+1]%MO1+MO1)%MO1;
	int d=(g1[b]-(ll)g1[a-1]*op1[b-a+1]%MO1+MO1)%MO1;
	if(c!=d)return 0;
	c=(h2[r]-(ll)h2[l-1]*op2[r-l+1]%MO2+MO2)%MO2;
	d=(g2[b]-(ll)g2[a-1]*op2[b-a+1]%MO2+MO2)%MO2;
	if(c!=d)return 0;
	return 1;
}

int sol(int l, int r, int a, int b)
{	
	if(mp[l][r][a].find(b)!=mp[l][r][a].end())return mp[l][r][a][b];
	if(b<a)return mp[l][r][a][b]=op[max(0,r-l)];
	if(r-l<a-b)return mp[l][r][a][b]=0;
	int u=A[l-1][t[a]-97];
	int Ans=0,cc;
	while(u<=r&&u){
		cc=b-a-(u-l);	
		if(cc<=0){
			Ans=(Ans+sol(l,u-1,a+1,b))%MO;
			u=A[u][t[a]-97];
			continue;
		}
		if(com(u+1,u+cc,b-cc+1,b)){
			Ans=(Ans+sol(l,u-1,a+1,b-cc))%MO;
		}
		u=A[u][t[a]-97];
	}
	return mp[l][r][a][b]=Ans;
}
inline void upd(int &a, int b)
{
	a=(a+b)%MO;
}

inline void _Sol_()
{
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%s",t+1);m=strlen(t+1);
	op[0]=1;F(i,1,N-2)op[i]=op[i-1]*2%MO;
	op1[0]=op2[0]=1;
	F(i,1,N-2)op1[i]=op1[i-1]*Ba1%MO1;
	F(i,1,N-2)op2[i]=op2[i-1]*Ba2%MO2;
	F(i,1,n)h1[i]=((ll)h1[i-1]*Ba1+s[i]-97)%MO1;
	F(i,1,n)h2[i]=((ll)h2[i-1]*Ba2+s[i]-97)%MO2;
	F(i,1,m)g1[i]=((ll)g1[i-1]*Ba1+t[i]-97)%MO1;
	F(i,1,m)g2[i]=((ll)g2[i-1]*Ba2+t[i]-97)%MO2;
	
	dF(i,n,0){
		F(j,0,25)A[i][j]=B[i+1][j];
		F(j,0,25)B[i][j]=B[i+1][j];
		if(i)B[i][s[i]-97]=i;
	}
	
	F(i,0,m)g[i+1][i]=1;
	F(i,0,m)if(s[1]==t[i])g[i][i]=1;
	
	int Ans=g[1][m];
	F(i,2,n){
		F(j,1,m)if(s[i]==t[j])upd(g[j][m],g[j+1][m]);
		F(j,0,m-i){
			if(s[i]==t[j])upd(g[j][j+i-1],g[j+1][j+i-1]);
			if(s[i]==t[j+i])upd(g[j+1][j+i],g[j+1][j+i-1]);
		}
		upd(Ans,g[1][m]);
		g[m+1][m]=op[i-1];
	}
	Ans=Ans*2%MO;
	priE(Ans);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}