#include <cstdio>
#include <algorithm>

int n,q,head[100001],nxt[200001],b[200001],v[200001],k,dis[100001],fa[100001],stk[100001],top,sum;
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void dfs(int x,int f){
	if(!f)dis[x]=0;
	fa[x]=f;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dis[b[i]]=dis[x]+v[i];
			dfs(b[i],x);
		}
}
struct que{
	int Root[100001],lson[100001],rson[100001],Val[100001],len[100001],time[100001],Fa[100001][21],ans[200001];
	int mxdep[100001],dis[100001],fa[100001],root;
	int merge(int a,int b){
		if(!a||!b)return a|b;
		if(Val[a]<Val[b])std::swap(a,b);
		rson[a]=merge(rson[a],b);
		if(len[lson[a]]<len[rson[a]])std::swap(lson[a],rson[a]);
		len[a]=len[rson[a]]+1;
		return a;
	}
	void getans(int x,int f,int v){
		if(!f)dis[x]=0;
		fa[x]=f;
		Fa[x][0]=f;
		for(int i=1;i<=20;i++)
			Fa[x][i]=Fa[Fa[x][i-1]][i-1];
		mxdep[x]=dis[x];
		for(int i=head[x];i;i=nxt[i])
			if(b[i]!=f){
				dis[b[i]]=dis[x]+::v[i];
				getans(b[i],x,::v[i]);
				mxdep[x]=std::max(mxdep[x],mxdep[b[i]]);
				Root[x]=merge(Root[x],Root[b[i]]);
			}
	//	for(int i=1;i<=n;i++)printf("%d %d %d\n",i,lson[i],rson[i]); 
		if(!Root[x])Root[x]=x;
		Val[Root[x]]+=v;
	}
	int solve(int x,int y){
		if(n<=2)return sum;
		else if(time[x]<=((y<<1)-1))return ans[(y<<1)-1];
		else{
			int tem=x;
			for(int j=20;~j;--j)
				if(time[Fa[tem][j]]>(y<<1)-1)tem=Fa[tem][j];
			tem=fa[tem];
//			printf("%d %d %d %d %d %d\n",tem,ans[y<<1],ans[(y<<1)-1],mxdep[x],dis[tem],mxdep[x]-dis[tem]+ans[(y<<1)-1]);
			return std::max(mxdep[x]-dis[tem]+ans[(y<<1)-2],ans[(y<<1)-1]-mxdep[tem]+mxdep[x]);
		}
	}
	void init(){
		getans(root,0,0);
		int cnt=0;
		while(Root[root]){
			++cnt;
			int tem=Root[root];
	//		printf("%d %d\n",tem,Val[tem]);
			ans[cnt]=ans[cnt-1]+Val[tem];
			Root[root]=merge(lson[Root[root]],rson[Root[root]]);
			while(tem){
				if(time[tem])break;
				time[tem]=cnt;
				tem=fa[tem];
			}
		}
		for(int i=cnt+1;i<=(n<<1);i++)ans[i]=ans[i-1];
	}
}q1,q2;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,u,v,l;i<n;i++)scanf("%d%d%d",&u,&v,&l),push(u,v,l),push(v,u,l),sum+=l;
	dfs(1,0);
	int mx=1,mx2=1;
	for(int i=1;i<=n;i++)if(dis[i]>dis[mx])mx=i;
	dfs(mx,0);
	for(int i=1;i<=n;i++)if(dis[i]>dis[mx2])mx2=i;
	q1.root=mx;q1.init();
	q2.root=mx2;q2.init();
	for(int i=1,lans=0,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		x=(x+lans-1)%n+1;
		y=(y+lans-1)%n+1;
		printf("%d\n",lans=std::max(q1.solve(x,y),q2.solve(x,y)));
	}
}