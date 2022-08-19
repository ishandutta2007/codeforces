#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

int n,q;
int get(){
	char ch=getchar();
	while(ch<'a'||ch>'z')ch=getchar();
	return ch-'a';
}
int head[20001],nxt[40001],b[40001],v[40001],k,fa[20001][21],dep[20001],big[20001],cha[20001],orig[20001];
int P[2]={998244353,1000000007};
int Pow[2][20001],inv[2][20001];
int qsm(int a,int b,int P){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*a*ans%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
struct hash{int h[2],len;}hsh[2][20001];
hash merge(hash a,hash b){return (hash){(1ll*a.h[0]*Pow[0][b.len]%P[0]+b.h[0])%P[0],(1ll*a.h[1]*Pow[1][b.len]%P[1]+b.h[1])%P[1],a.len+b.len};}
hash del1(hash a,hash b){
	return (hash){
		1ll*(a.h[0]+P[0]-b.h[0])*inv[0][b.len]%P[0],
		1ll*(a.h[1]+P[1]-b.h[1])*inv[1][b.len]%P[1],
		a.len-b.len};
}
hash del2(hash a,hash b){
	return (hash){
		(a.h[0]+P[0]-1ll*b.h[0]*Pow[0][a.len-b.len]%P[0])%P[0],
		(a.h[1]+P[1]-1ll*b.h[1]*Pow[1][a.len-b.len]%P[1])%P[1],
		a.len-b.len};
}
bool operator==(hash a,hash b){return a.h[0]==b.h[0]&&a.h[1]==b.h[1];}
int ans[20001],mx[20001],root,full,size[20001];
int son[20001][26],cnt;
bool vis[20001];
int Newnode(){
	memset(son[cnt],0,sizeof son[cnt]);
	size[cnt]=orig[cnt]=0;
	return cnt++;
}
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void dfs(int x,int f){
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=20;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			hsh[0][b[i]]=merge((hash){664278*(v[i]+1),123453*(v[i]+1),1},hsh[0][x]);
			hsh[1][b[i]]=merge(hsh[1][x],(hash){664278*(v[i]+1),123453*(v[i]+1),1});
			cha[b[i]]=v[i];
			dfs(b[i],x);
		}
}
int LCA(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int lift(int x,int l){
	for(int i=20;~i;--i)
		if(l>=(1<<i))l^=(1<<i),x=fa[x][i];
	return x;
}
std::pair<int,hash> get(int x,int y,int l=-1,int lca=0){
	if(!~l)l=(dep[x]+dep[y]-(dep[lca]<<1));
//	printf("get %d %d %d %d\n",x,y,l,lca);
	if(dep[x]-dep[lca]>=l){
		int p=lift(x,l);
//		printf("%d %d\n",del1(hsh[0][x],hsh[0][p]).h[0],del1(hsh[0][x],hsh[0][p]).h[1]);
		return std::make_pair(p,del1(hsh[0][x],hsh[0][p]));
	}
	else{
		int p=lift(y,(dep[x]+dep[y]-(dep[lca]<<1))-l);
//		printf("%d %d %d %d %d %d\n",(dep[x]+dep[y]-(dep[lca]<<1))-l,hsh[0][x].h[0],hsh[0][x].h[1],hsh[0][p].h[0],hsh[0][p].h[1],p);
//		printf("%d %d\n",hsh[1][p].h[0],
//			hsh[1][p].h[1]);
		return std::make_pair(p,merge(del1(hsh[0][x],hsh[0][lca]),del2(hsh[1][p],hsh[1][lca])));
	}
}
void getroot(int x,int f){
	size[x]=1,mx[x]=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]]){
			getroot(b[i],x);
			size[x]+=size[b[i]];
			mx[x]=std::max(mx[x],size[b[i]]);
		}
	mx[x]=std::max(mx[x],full-size[x]);
	if(mx[x]<mx[root])root=x;
}
int Tem[20001];
void gettree(int x,int f,int node){
//	printf("gettree %d %d\n",x,node);
	++size[node],++orig[node];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]]){
			if(!son[node][v[i]])son[node][v[i]]=Newnode();
			gettree(b[i],x,son[node][v[i]]);
		}
}
void getsiz(int x,int f){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]]){
			getsiz(b[i],x);
			size[x]+=size[b[i]];
		}
}
std::map<std::pair<int,int>,int>map; 
std::vector<std::pair<int,int> >que[20001]; 
void init(int x,int B,hash now){
//	printf("%d %d %d %d %d\n",x,B,now.h[0],now.h[1],size[x]);
	map[std::make_pair(now.h[0],now.h[1])]=x;
	big[x]=B;
	B+=size[x];
	for(int i=0;i<26;++i)
		if(son[x][i]){
			init(son[x][i],B,merge(now,(hash){664278*(i+1),123453*(i+1),1}));
			B+=size[son[x][i]];
			size[x]+=size[son[x][i]];
		}
}
void getans(int x,int f,int y){
	for(int i=0;i<que[x].size();i++){
//	printf("*%d\n",map.count(std::make_pair(9964170,1851795)));
		int X=x,Y=que[x][i].first,lca1=LCA(X,Y),lca2=LCA(X,root),node,cmp;
		int dis1=dep[X]+dep[Y]-(dep[lca1]<<1),dis2=dep[X]+dep[root]-(dep[lca2]<<1);
		int l=1,r=std::min(dis1,dis2),mid,ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(get(X,Y,mid,lca1).second==get(X,root,mid,lca2).second)ans=mid,l=mid+1;
			else r=mid-1;
		}
		int cha1=(ans>=dep[X]-dep[lca1])?cha[lift(Y,dis1-ans-1)]:cha[get(X,Y,ans,lca1).first];
		int cha2=(ans>=dep[X]-dep[lca2])?cha[lift(root,dis2-ans-1)]:cha[get(X,root,ans,lca2).first];
		node=get(X,Y,ans,lca1).first;
		if(cha1<cha2)cmp=1;
		else if(cha1>cha2)cmp=-1;
		else cmp=0;
//		printf("%d %d %d %d %d %d %d %d %d %d %c %c\n",X,Y,root,cmp,ans,lca1,lca2,node,dis1,dis2,cha1+'a',cha2+'a');
		if(ans==dis2&&dis1>dis2){
			lca1=LCA(node,Y);
			l=1,r=dis1-=ans;
			ans=0;
			std::pair<int,int> D=std::make_pair(0,0);
//			printf("%d %d\n",node,Y);
			while(l<=r){
				mid=(l+r)>>1;
				auto now=get(node,Y,mid,lca1).second;
//				printf("%d %d %d %d\n",mid,now.h[0],now.h[1],map.count(std::make_pair(now.h[0],now.h[1])));
				if(map.count(std::make_pair(now.h[0],now.h[1])))D=std::make_pair(now.h[0],now.h[1]),ans=mid,l=mid+1;
				else r=mid-1;
			}
//			printf("%d %d\n",D.first,D.second);
			int Cha=(ans>=dep[node]-dep[lca1])?cha[lift(Y,dis1-ans-1)]:cha[get(node,Y,ans,lca1).first];
			int ind=map[D];
//			printf("--%d %d %d %c\n",ans,dis1,ind,Cha+'a');
			if(ans!=dis1){
				::ans[que[x][i].second]+=y*orig[ind];
				for(int c=0;c<Cha;c++)
					if(son[ind][c]){
						::ans[que[x][i].second]+=y*size[son[ind][c]];
//						printf("%d %d %d\n",son[ind][c],size[son[ind][c]],::ans[que[x][i].second]);
					}
			}
//			printf("%d\n",::ans[que[x][i].second]);
			::ans[que[x][i].second]+=y*big[ind];
		}
		else if(cmp==-1&&ans!=dis1&&ans!=dis2)::ans[que[x][i].second]+=y*full;
	}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]])
			getans(b[i],x,y);
}
void dfs(int x){
	printf("dfs %d ",x);
	for(int i=0;i<26;i++)
		if(son[x][i])printf("(%c %d)",i+'a',son[x][i]);
	printf("%d %d\n",big[x],size[x]);
	for(int i=0;i<26;i++)if(son[x][i])dfs(son[x][i]);
}
void solve(int rt){
//	printf("solve %d %d\n",rt,full);
	vis[rt]=1;
	cnt=0;
	Newnode();
	gettree(rt,0,0);
	map.clear();
	init(0,0,(hash){0,0,0});
//	dfs(0);
	getans(rt,0,1);
//	putchar('&');
//	for(int i=1;i<=q;i++)printf("%d ",ans[i]);putchar('\n');
	for(int i=head[rt];i;i=nxt[i])
		if(!vis[b[i]]){
			root=rt;
			cnt=0;
			getsiz(b[i],rt);
			full=size[b[i]];
			Newnode();
//			printf("%d\n",cnt);
			gettree(b[i],rt,son[0][v[i]]=Newnode());
			map.clear();
			init(0,0,(hash){0,0,0});
//			dfs(0);
			getans(b[i],rt,-1);
//	putchar('&');
//	for(int i=1;i<=q;i++)printf("%d ",ans[i]);putchar('\n');
			mx[root=0]=full;
			getroot(b[i],rt);
			solve(root);
		}
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<2;i++){
		Pow[i][0]=1;
		for(int j=1;j<=n;j++)Pow[i][j]=1ll*Pow[i][j-1]*46327867%P[i];
		inv[i][0]=1;
		int Inv=qsm(46327867,P[i]-2,P[i]);
		for(int j=1;j<=n;j++)inv[i][j]=1ll*inv[i][j-1]*Inv%P[i];
	}
	for(int i=1,u,v,c;i<n;i++){
		scanf("%d%d",&u,&v);
		c=get();
		push(u,v,c),push(v,u,c);
	}
	dfs(1,0); 
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		que[x].push_back(std::make_pair(y,i));
	}
	mx[root=0]=full=n;
	getroot(1,0);
	solve(root);
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]-1);
}