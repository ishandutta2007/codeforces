#include <cstdio>
#include <vector>
#define int long long

int fa[400010],ch[400010][2];
long long si[400010],size[400010],G[400010];
bool son(int x){return ch[fa[x]][1]==x;}
bool isroot(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
void pushup(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+si[x]+1;}
void Rotate(int x){
    if(!x||!fa[x]||isroot(x))return;
    int faz=fa[x],fazz=fa[faz],g=son(x);
    fa[x]=fazz;
    if(!isroot(faz))ch[fazz][son(faz)]=x;
    fa[ch[x][!g]]=faz;
    ch[faz][g]=ch[x][!g];
    fa[faz]=x;
    ch[x][!g]=faz;
    pushup(faz);
    pushup(x);
}
void splay(int node){
    while(!isroot(node)){
        if(!isroot(fa[node]))
            if(son(fa[node])^son(node))Rotate(node);
            else Rotate(fa[node]);
        Rotate(node);
    }
    pushup(node);
}
void access(int x){
    for(int y=0;x;y=x,x=fa[x]){
        splay(x);
        si[x]+=size[ch[x][1]];
        si[x]-=size[y];
        G[x]+=1ll*size[ch[x][1]]*size[ch[x][1]];
		G[x]-=1ll*size[y]*size[y]; 
		ch[x][1]=y;
		pushup(x);
    }
}
void link(int x,int y){
	access(x);
	splay(x);
	access(y);
	splay(y);
    fa[x]=y;
    si[y]+=size[x];
    G[y]+=1ll*size[x]*size[x];
    pushup(y);
}
int find(int x){
    access(x);
    splay(x);
    while(ch[x][0])x=ch[x][0];
    return x;
}
void cut(int x,int y){
	access(x);
	splay(y);
	ch[y][1]=fa[x]=0;
	pushup(y);
}
int head[400010],nxt[800001],b[800001],k,n,m,c[400010],Fa[400010];
bool col[400010];
std::vector<std::pair<int,int> >que[400001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	Fa[x]=fa[x]=f;
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
			size[x]+=size[b[i]];
			G[x]+=1ll*size[b[i]]*size[b[i]];
		}
	si[x]=size[x]-1;
}
long long ans[400010];
long long f(int x){
	return 1ll*(size[ch[x][0]]+size[ch[x][1]])*(size[ch[x][0]]+size[ch[x][1]])+G[x];
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",c+i),que[c[i]].push_back(std::make_pair(0,i));
	for(int i=1,u,v;i<n;i++)scanf("%lld%lld",&u,&v),push(u,v),push(v,u);
	push(n+1,1);
	dfs(n+1,0);
	for(int i=1,u,col;i<=m;i++){
		scanf("%lld%lld",&u,&col);
		if(c[u]==col)continue;
		que[col].push_back(std::make_pair(i,u));
		que[c[u]].push_back(std::make_pair(i,-u));
		c[u]=col;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)que[i].size();j++){
			int t=que[i][j].first;
//			if(t)continue;
			if(que[i][j].second>0){
				int u=que[i][j].second,v=Fa[u];
				col[u]^=1;
				access(u);
				splay(u);
				int sz=size[u]-si[find(u)]-1;
				splay(find(u));
				ans[t]+=1ll*sz*sz;
				cut(u,v);
				ans[t]-=f(u)+1ll*(sz-size[u])*(sz-size[u]);
			}
			else{
				int u=-que[i][j].second,v=Fa[u];
				col[u]^=1;
				splay(u);
				int tm=size[u];
				ans[t]+=f(u);
				link(u,v);
				access(u);
				splay(u);
				int sz=size[u]-si[find(u)]-1;
				ans[t]-=1ll*sz*sz-1ll*(sz-tm)*(sz-tm);
				splay(find(u));
			}
		}
		for(int j=0;j<(int)que[i].size();j++){
			int u=que[i][j].second;
			if(u<0)u=-u;
			if(col[u])link(u,Fa[u]),col[u]=0;
		}
	}
	for(int i=1;i<=m;i++)ans[i]+=ans[i-1];
	for(int i=0;i<=m;i++)printf("%lld\n",ans[i]);
}
//10 15
//3 6 6 9 7 6 4 7 8 9
//2 4
//9 2
//6 4
//1 9
//3 1
//8 1
//5 8
//10 6
//7 4
//2 8
//10 1
//6 8
//3 5
//7 10
//2 4
//10 6
//5 1
//4 8
//1 10
//7 6
//1 1
//7 1
//6 8
//7 7