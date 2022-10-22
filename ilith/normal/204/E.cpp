#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int N=2e5+7;
int n,k,ch[N][26],len[N],fa[N],las,C,in[N],T,sz[N],dep[N],P[N][19];
char s[N];
vector<int>a[N],b[N];
void add(int c){
	int x=++C,p=las;
	len[x]=len[p]+1,las=x;
	for(;~p&&!ch[p][c];p=fa[p])ch[p][c]=x;
	if(!~p)return;
	int q=ch[p][c];
	if(len[q]==len[p]+1)return void(fa[x]=q);
	fa[++C]=fa[q],len[C]=len[p]+1,fa[x]=fa[q]=C;
	FOR(i,0,25)ch[C][i]=ch[q][i];
	for(;~p&&ch[p][c]==q;p=fa[p])ch[p][c]=C;
}
void dfs(int x){
	in[x]=++T;
	FOR(i,1,18)P[x][i]=P[P[x][i-1]][i-1];
	for(int to:a[x])dep[to]=dep[x]+1,*P[to]=x,dfs(to);
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	ROF(i,18,0)if(dep[u]-(1<<i)>=dep[v])u=P[u][i];
	if(u==v)return u;
	ROF(i,18,0)if(P[v][i]!=P[u][i])v=P[v][i],u=P[u][i];
	return *P[u];
}
void add(vi v){
	sort(v.begin(),v.end(),[&](int x,int y){return in[x]<in[y];}),las=0;
	for(int k:v){
		if(las)--sz[LCA(las,k)];
		++sz[las=k];
	}
}
void Dfs(int x){
	for(int to:a[x])Dfs(to),sz[x]+=sz[to];
}
int find(int x){
	ROF(i,18,0)if(sz[P[x][i]]<k)x=P[x][i];
	if(sz[x]<k)x=*P[x];
	return len[x];
}
signed main(){
	scanf("%d%d",&n,&k),*fa=-1;
	FOR(i,1,n){
		scanf("%s",s+1),las=0;
		int len=strlen(s+1);
		b[i].reserve(len*2+2);
		FOR(j,1,len)add(s[j]-'a'),b[i].pbk(las);
	}
	FOR(i,1,C)a[fa[i]].push_back(i);
	dfs(0);
	FOR(i,1,n)add(b[i]);
	Dfs(0);
	FOR(i,1,n){
		ll ans=0;
		for(int k:b[i])ans+=find(k);
		printf("%lld ",ans);
	}
	return 0;
}