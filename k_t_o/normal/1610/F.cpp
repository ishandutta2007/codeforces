//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx") 
#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3f
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

#define N 3000005
int n,m,num,x,y,z,k,l,t,p,flag[N];
int head[N],vet[N],cost[N],ne[N],q[N],d1[N],d2[N],od1[N],od2[N];

int u[N],v[N],w[N],tt,S,Ans[N],D[N],_Ans;
int Vi[N];
void add(int a,int b,int c){
	ne[++num]=head[a];
	head[a]=num;
	vet[num]=b;
	cost[num]=c;
	d1[a]++;d2[b]++;
}
void dfs(int u){
	Vi[u]=1;
	for (int e=head[u];e;e=head[u]){
		while(e&&flag[abs(cost[e])])e=ne[e];
		int v=vet[e];
		head[u]=e;
		if(!e)continue;
		flag[abs(cost[e])]=1;
		dfs(v);
		q[++t]=cost[e];
	}
}


inline void _Sol_()
{
	read(n); read(m);
	F(i,1,m){
		read(u[i]); read(v[i]); read(w[i]);
		if(w[i]==1){
			++tt;
			add(u[i],v[i],tt);
			add(v[i],u[i],-tt);
//			G[u].push_back(v);
			od1[u[i]]^=1;
//			G[v].push_back(u);
			od1[v[i]]^=1;
		} else {
			++tt;
			add(u[i]+n,v[i]+n,tt);
			add(v[i]+n,u[i]+n,-tt);
//			G[u+n].push_back(v+n);
			od2[u[i]]^=1;
//			G[v+n].push_back(u+n);
			od2[v[i]]^=1;
		}
	}
	S=n+n+1; 
	F(i,1,n){
		if(od1[i]&&!od2[i])++tt,add(S,i,tt),add(i,S,-tt);
		if(!od1[i]&&od2[i])++tt,add(S,i+n,tt),add(i+n,S,-tt);
		if(od1[i]&&od2[i])++tt,add(i,i+n,tt),add(i+n,i,-tt);
	}
	F(i,1,S)if(!Vi[i]) dfs(i);
	
	F(i,1,t){
		if(q[i]<0){
			Ans[-q[i]]=2;
		} else Ans[q[i]]=1;
	}
	
	F(i,1,m){
		if(Ans[i]==1) D[u[i]]+=w[i],D[v[i]]-=w[i];
		else D[u[i]]-=w[i],D[v[i]]+=w[i];
	}
	
	F(i,1,n)if(abs(D[i])==1) ++_Ans;
	priE(_Ans);
	F(i,1,m)prin(Ans[i]);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}