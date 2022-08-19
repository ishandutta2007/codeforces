#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

int n;
int head[100001],nxt[200001],b[200001],k,size[100001],mx[100001],root;
int dep[100001];
int f[100001],d[100001],fa[100001];
const int P=1004535809;
int Pow[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void getroot(int x,int f){
	size[x]=1,mx[x]=0;
	fa[x]=f;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			getroot(b[i],x);
			size[x]+=size[b[i]];
			mx[x]=std::max(mx[x],size[b[i]]);
		}
	mx[x]=std::max(mx[x],n-size[x]);
	if(mx[x]<mx[root])root=x; 
}
int cnt;
int hsh[100001],hsh2[100001];
void dfs1(int x,int f,int *hsh,int P){
	std::vector<int>tem;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x,hsh,P);
			dep[x]=std::max(dep[x],dep[b[i]]+1);
			tem.push_back(1ll*hsh[b[i]]*1145141%P*Pow[dep[b[i]]+1]%P);
		}
	tem.push_back(1145141);
	std::sort(tem.begin(),tem.end());
	for(int i=0;i<(int)tem.size();i++)
		hsh[x]=((1ll*hsh[x]*Pow[i]%P)+tem[i])%P;
}
void getans(int x,int F){
	std::set<std::pair<int,int> >set;
	f[x]=(d[x]<=3);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F&&!set.count(std::make_pair(hsh[b[i]],hsh2[b[i]]))){
			set.insert(std::make_pair(hsh[b[i]],hsh2[b[i]]));
			getans(b[i],x);
			f[x]+=f[b[i]];
		}
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	Pow[0]=1;
	for(int i=1;i<=n;i++)Pow[i]=1ll*Pow[i-1]*467324887%P;
	if(n<=2){
		puts("1");
		return 0;
	}
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u),++d[u],++d[v];
	mx[root=0]=n;
	getroot(1,0);
	if(n%2==0&&mx[root]==(n>>1)){
		int p=fa[root];
		for(int i=head[root];i;i=nxt[i])
			if(size[b[i]]==n>>1)p=b[i];
		dfs1(root,p,hsh,998244353);
		dfs1(root,p,hsh2,1004535809);
		dfs1(p,root,hsh,998244353);
		dfs1(p,root,hsh2,1004535809);
		if(hsh[p]==hsh[root]&&hsh2[p]==hsh2[root]){
			getans(root,p);
			printf("%d\n",f[root]);
		}
		else{
			getans(root,p);
			getans(p,root);
			printf("%d\n",f[root]+f[p]);
		}
	}
	else{
		dfs1(root,0,hsh,998244353);
		dfs1(root,0,hsh2,1004535809);
		getans(root,0);
		printf("%d\n",f[root]);
	}
}