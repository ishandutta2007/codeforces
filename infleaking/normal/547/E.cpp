#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int fail[N],c[N][26];
int tr[N],dfn[N],ed[N];
vector<int> w[N],h[N];
int n,loc[N],q;
char s[N];
int ans[3*N],t;
struct que{int ty,x,i;};
vector<que> p[N];
int d[N],lim;
void dfs(int x){
	dfn[x]=ed[x]=++t;
	for (int z:w[x]){
		dfs(z);
		ed[x]=ed[z];
	}
}
#define low(x) (x&(-x))
void add(int x,int v){
	for (;x<=lim;x+=low(x))tr[x]+=v;
}
int qsum(int x){
	int ans=0;
	for (;x;x-=low(x))ans+=tr[x];
	return ans;
}
int main(){
	cin>>n>>q;t=1;
	for (int i=1;i<=n;i++){
		scanf("%s",s+loc[i-1]);
		loc[i]=strlen(s+loc[i-1])+loc[i-1];
		int now=1;
		for (int j=loc[i-1];j<loc[i];j++){
			int x=s[j]-'a';
			if (!c[now][x])c[now][x]=++t;
			now=c[now][x];
			h[i].push_back(now);
		}
	}lim=t;
	int l=0,r=0;
	for (int i=0;i<26;i++)
		if (c[1][i])d[++r]=c[1][i],fail[c[1][i]]=1;
	while (l<r){
		int x=d[++l];
		for (int i=0;i<26;i++){
			if (!c[x][i])continue;
			int k=fail[x];
			while (!c[k][i]&&k>1)k=fail[k];
			fail[c[x][i]]=c[k][i]?c[k][i]:1;
			d[++r]=c[x][i];
		}
	}
	for (int i=2;i<=t;i++)w[fail[i]].push_back(i);
	t=0;
	dfs(1);
	for (int i=1;i<=q;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		p[l-1].push_back((que){-1,k,i});
		p[r].push_back((que){1,k,i});
	}
	for (int i=1;i<=n;i++){
		for (int j:h[i])add(dfn[j],1);
		for (auto x:p[i])
			ans[x.i]+=x.ty*(qsum(ed[h[x.x].back()])-qsum(dfn[h[x.x].back()]-1));
	}
	for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
}