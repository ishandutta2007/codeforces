#include <cstdio>
#include <algorithm>
#define int long long

using std::max;

int fa[200001][21],mx[200001][21],head[200001],nxt[400001],b[400001],v[400001],k,F[200001],n,m,dep[200001];
long long fin[200001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
int find(int x){return F[x]?F[x]=find(F[x]):x;}
struct point{int u,v,val,ord;}num[200001];
bool cmp(point a,point b){return a.val<b.val;}
bool vis[200001];
void dfs(int x,int f,int val){
	fa[x][0]=f;
	mx[x][0]=val;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1],mx[x][i]=max(mx[x][i-1],mx[fa[x][i-1]][i-1]);
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x,v[i]);
}
int LCA(int x,int y){
	int tot=0;
	if(dep[x]<dep[y])x^=y^=x^=y;
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])tot=max(tot,mx[x][i]),x=fa[x][i];
	if(x==y)return tot;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])tot=max(tot,max(mx[x][i],mx[y][i])),x=fa[x][i],y=fa[y][i];
	return max(tot,max(mx[x][0],mx[y][0]));
}
signed main(){
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%I64d%I64d%I64d",&num[i].u,&num[i].v,&num[i].val);
		num[i].ord=i;
	}
	std::sort(num+1,num+m+1,cmp);
	long long ans=0;
	for(int i=1;i<=m;i++){
		int x=find(num[i].u),y=find(num[i].v);
		if(x==y)continue;
		vis[i]=1;
		F[x]=y;
		push(num[i].u,num[i].v,num[i].val);
		push(num[i].v,num[i].u,num[i].val);
		ans+=num[i].val;
	}
	dfs(1,0,0);
	for(int i=1;i<=m;i++){
		if(vis[i])fin[num[i].ord]=ans;
		else{
			fin[num[i].ord]=ans-LCA(num[i].u,num[i].v)+num[i].val;
		}
	}
	for(int i=1;i<=m;i++)printf("%I64d\n",fin[i]);
}