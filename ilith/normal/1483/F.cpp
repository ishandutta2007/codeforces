#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
using namespace std;
typedef long long ll;
const int N=2e6+7;
int n,ch[N][27],fa[N],F[N],u,C,in[N],ot[N],T,id[N],tp[N],D[N];
vector<int>a[N];
string s[N];
int q[N],l=1,r,p[N],tot;
void dfs(int x,int f=-1){
	in[x]=++T,tp[x]=(id[f]?f:tp[f]);
	for(int to:a[x])dfs(to,x);
	ot[x]=T;
}
int rs,t[N],vs[N],ans;
void upd(int x,int v){for(;x<=T;x+=(x&-x))t[x]+=v;}
int qry(int x){for(rs=0;x;x&=(x-1))rs+=t[x];return rs;}
int get(int u,int i){return id[u]==i||!id[u]?tp[u]:u;}
signed main(){
	cin>>n;
	FOR(i,1,n){
		cin>>s[i],u=0;
		for(char k:s[i]){
			int &f=ch[u][k-'a'];
			F[f?f:f=++C]=u,D[f]=D[u]+1,u=f;
		}
		p[i]=u,id[u]=i;
	}
	FOR(i,0,25)if(ch[0][i])q[++r]=ch[0][i];
	while(l<=r){
		int x=q[l++],*f=ch[x];
		a[fa[x]].pbk(x);
		FOR(i,0,25)(f[i]?fa[q[++r]=f[i]]:f[i])=ch[fa[x]][i];
	}
	dfs(0),u=0;
	FOR(i,1,n){
		for(char k:s[i])upd(in[u=ch[u][k-'a']],1);
		int v=u,t;
		for(int mn=1e7,x=u;x;x=F[x]){
			t=get(x,i);
			if(D[x]-D[t]<mn)mn=D[x]-D[t],++vs[t];
		}
		for(;u;u=F[u],vs[t]=0){
			t=get(u,i);
			if(t&&id[t])ans+=(vs[t]==qry(ot[t])-qry(in[t]-1));
		}
		for(;v;v=F[v])upd(in[v],-1);
	}
	printf("%d",ans);
	return 0;
}