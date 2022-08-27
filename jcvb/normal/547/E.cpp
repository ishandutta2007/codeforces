#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define pi ((db)3.14159265358979323846264338327950288L)
#define buli __builtin_popcountll
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
#define lld "%I64d"
#else
#define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n,q;
char buf[555555],*ptr=buf;
char* s[222222];int len[222222];



int fail[250000];
int ch[250000][26];
int lea[255555];
int nd;
int insert(char *str){
	int cur=0;
	for (int i=0;str[i];i++){
		if(ch[cur][str[i]-'a'])cur=ch[cur][str[i]-'a'];
		else cur=ch[cur][str[i]-'a']=++nd;
	}
	return cur;
}
void build(){
	static int qu[250000];int p,q;
	p=q=0;
	qu[q++]=0;
	int u,v;
	while(p<q){
		u=qu[p++];
		for (int i=0;i<26;i++)if(ch[u][i]){
			qu[q++]=ch[u][i];
			v=fail[u];
			while(v && !ch[v][i])v=fail[v];
			fail[ch[u][i]]=ch[v][i];
			if(fail[ch[u][i]]==ch[u][i])fail[ch[u][i]]=0;
		}
	}
}
struct quer{
	int ti,vid,qid;int sg;
}qe[1111111];int qtot=0;
int cmp(const quer&a,const quer&b){
	return a.ti<b.ti;
}
ll ou[555555];

namespace tree{
	// manually set n = number of vertices 
	// vertex index from 1 to n
	// first call tree_init();
	// ae(u,v) only one direction

	const int TREE_MAXV=300000+5;
	struct edge{int v,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
	int n;
	void ae(int u,int v){
		e[etot].v=v;
		e[etot].next=g[u];g[u]=etot++;
	}
	int dfn[TREE_MAXV],rig[TREE_MAXV],pre[TREE_MAXV];
	int seq[TREE_MAXV*2];
	void dfs(int rt){
		static int stk[TREE_MAXV],cur[TREE_MAXV];
		int top=0,ind=0;
		pre[rt]=0;
		stk[++top]=rt;
		cur[top]=g[rt];
		while(top){
			int u=stk[top];
			if(cur[top]==g[u]){
				dfn[u]=++ind;
				seq[ind]=u;	// starts
			}
			if(cur[top]==-1){
				rig[u]=ind;	// ends
				//rig[u]=++ind;
				top--;
			}else{
				int v=e[cur[top]].v;cur[top]=e[cur[top]].next;
				if(v==pre[u])continue;
				pre[v]=u;
				stk[++top]=v;
				cur[top]=g[v];
				// new node information
			}
		}
	}

	void tree_init(){
		static bool ini=0;
		if(!ini){
			ini=1;
			memset(g,-1,sizeof(g));
		}else{
			for (int i=0;i<=n;i++)g[i]=-1;
		}
		etot=0;
	}
};

ll bit[333333];
void bitupd(int x,int de){
	for(;x<=nd+2;x+=x&-x)bit[x]+=de;
}
ll bitque(int x){
	ll su=0;
	for(;x;x-=x&-x)su+=bit[x];
	return su;
}
void add(int id){
	bitupd(tree::dfn[id],1);
}
ll ask(int id){
	return bitque(tree::rig[id])-bitque(tree::dfn[id]-1);
}
void walk(char *s){
	int cur=0;
	for(int i=0;s[i];i++){
		cur=ch[cur][s[i]-'a'];
		add(cur);
	}
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(q);
	rep(i,1,n+1){
		scanf("%s",ptr);
		len[i]=strlen(ptr);
		s[i]=ptr;
		ptr+=len[i]+1;
	}
	rep(i,1,n+1){
		lea[i]=insert(s[i]);
	}
	build();
	rep(i,1,q+1){
		int l,r,k;
		gn(l);gn(r);gn(k);
		qe[++qtot]=(quer){l-1,lea[k],i,-1};
		qe[++qtot]=(quer){r,lea[k],i,1};
	}
	sort(qe+1,qe+1+qtot,cmp);
	tree::tree_init();
	rep(i,1,nd+1){
		tree::ae(fail[i],i);
	}
	tree::dfs(0);

	int cur=1;
	rep(i,0,n+1){
		while(cur<=qtot && qe[cur].ti==i){
			ou[qe[cur].qid]+=ask(qe[cur].vid)*qe[cur].sg;
			cur++;
		}
		if(i==n)break;
		walk(s[i+1]);
	}
	rep(i,1,q+1)printf(lld"\n",ou[i]);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}