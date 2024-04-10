#include <cstdio>
#include <queue>

int n,m;
char map[1000001];
long long f[1000001],g[1000001];
char get(){
	char ch=getchar();
	while(ch!='.'&&ch!='#')ch=getchar();
	return ch;
}
int head[1000001],nxt[2000001],b[2000001],k,d[2000001],ord[2000001],cnt,fa[1000001][21],dep[1000001],par[1000001],size[1000001];
std::queue<int>q;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	++d[t];
}
void add(int x,int f){
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=20;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
}
int LCA(int x,int y){
	if(!~x)return y;
	if(dep[x]<dep[y])x^=y^=x^=y;
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int hash(int i,int j){return (i-1)*m+j;}
bool con[1000001];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			map[hash(i,j)]=get();
			con[hash(1,1)]=1;
	for(int i=1;i<=n*m;i++)par[i]=-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(!con[hash(i,j)])continue;
			if(i<n&&map[hash(i,j)]!='#'&&map[hash(i+1,j)]!='#')push(hash(i,j),hash(i+1,j)),con[hash(i+1,j)]=1;
			if(j<m&&map[hash(i,j)]!='#'&&map[hash(i,j+1)]!='#')push(hash(i,j),hash(i,j+1)),con[hash(i,j+1)]=1;
		}
	q.push(1),par[1]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		add(now,par[now]);
		for(int i=head[now];i;i=nxt[i]){
			par[b[i]]=LCA(par[b[i]],now);
			if(!(--d[b[i]]))q.push(b[i]);
		}
	}
	if(!con[hash(n,m)])puts("0");
	else if(par[hash(n,m)]>1)puts("1");
	else puts("2");
}