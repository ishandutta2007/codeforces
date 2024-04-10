#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define pb push_back
#define ll long long
using namespace std;
const int N=2e5+5,M=5e5+5;
int n,q,l,r,k,w[N],d[N],ds;
int s[N][26],t=1,df[N],en[N],fa[N];
char c[N];
vector<int>a[N],e[N];
struct nod{int l,r,k,i;};
vector<nod>qu[N];
int ans[M],T[N];
void dfs(int x){
	df[x]=++ds;d[ds]=x;
	for(int i:e[x])dfs(i);
	en[x]=ds;
}
void ch(int x){
	for(;x<=n;x+=x&-x)++T[x];
}
int qry(int x){
	int s=0;
	for(;x;x&=x-1)s+=T[x];
	return s;
}
int main(){
	cin>>n>>q;
	fo(i,1,n){
		scanf("\n%s",c+1);
		int le=strlen(c+1),j=1;
		fo(l,1,le){
			if(!s[j][c[l]-='a'])s[j][c[l]]=++t;
			j=s[j][c[l]];a[j].pb(i);
		}
		w[i]=j;
	}
	fo(i,0,25)s[0][i]=1;
	d[ds=1]=1;
	for(int l=0,x;x=d[++l],l<=ds;)
		fo(i,0,25)if(s[x][i]){
			int y=s[x][i];
			d[++ds]=y;
			int z=fa[x];
			for(;!s[z][i];)z=fa[z];
			fa[y]=s[z][i];
			e[fa[y]].pb(y);
		}
	ds=0;dfs(1);
	fo(i,1,q){
		scanf("%d%d%d",&l,&r,&k);
		qu[df[w[k]]-1].pb((nod){l,r,-1,i});
		qu[en[w[k]]].pb((nod){l,r,1,i});
	}
	fo(i,1,t){
		for(int j:a[d[i]])ch(j);
		for(nod j:qu[i])ans[j.i]+=(qry(j.r)-qry(j.l-1))*j.k;
	}
	fo(i,1,q)printf("%d\n",ans[i]);
}