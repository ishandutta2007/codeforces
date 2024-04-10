#include <cstdio>
#include <algorithm>

int ch[200001][2],col[200001],size[200001],lazy1[200001],c[400001],n,q,fa[200001];

void update(int ind,int num){if(!ind)return;for(;ind<=n+q;ind+=ind&-ind)c[ind]+=num;}
int query(int ind){int tot=0;for(;ind;ind-=ind&-ind)tot+=c[ind];return tot;}

bool lazy2[200001];
void spread(int x){
	if(lazy1[x]){
		col[x]=lazy1[x];
		lazy1[ch[x][0]]=lazy1[ch[x][1]]=lazy1[x];
		lazy1[x]=0;
	}
	if(lazy2[x]){
		std::swap(ch[x][0],ch[x][1]);
		lazy2[ch[x][0]]^=1;
		lazy2[ch[x][1]]^=1;
		lazy2[x]^=1;
	}
}
inline void pushup(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+1;}
inline bool isroot(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
inline bool son(int x){return ch[fa[x]][1]==x;}
void rotate(int x){
	if(!x||!fa[x])return;
	int faz=fa[x],fazz=fa[faz],g=son(x);
	fa[x]=fazz;
	if(!isroot(faz))ch[fazz][son(faz)]=x;
	ch[faz][g]=ch[x][!g];
	fa[ch[x][!g]]=faz;
	ch[x][!g]=faz;
	fa[faz]=x;
	pushup(faz);
	pushup(x);
}
void clear(int x){
	if(!isroot(x))clear(fa[x]);
	spread(x);
}
void splay(int x){
	clear(x);
	while(!isroot(x)){
		if(!isroot(fa[x])){
			if(son(x)^son(fa[x]))rotate(x);
			else rotate(fa[x]);
		}
		rotate(x);
	}
}
void access(int x,int c){
	int y=0;
	for(;x;y=x,x=fa[x]){
		splay(x);
		update(col[x],-size[x]);
		update(col[x],size[ch[x][1]]);
		ch[x][1]=y;
		pushup(x);
	}
	lazy1[y]=c;
	update(c,size[y]);
}
int head[200001],nxt[400001],b[400001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			fa[b[i]]=x;
			dfs(b[i],x);
		}
}
int que(int x){
	splay(x);
	return query(col[x]-1)+size[ch[x][1]]+1;
}
char str[101];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	n=read(),q=read();
	for(int i=1,s,t;i<n;i++){
		s=read(),t=read();
		push(s,t);
		push(t,s);
	}
	dfs(1,0);
	col[1]=1;
	update(1,1);
	for(int i=2;i<=n;i++){
		access(i,i);
		splay(i);
		lazy2[i]^=1;
	}
	int now=n;
//		for(int j=1;j<=n;j++)printf("%d ",que(j));putchar('\n');
//		for(int j=1;j<=n;j++)clear(j);
//		for(int j=1;j<=n;j++)printf("%d %d %d %d %d %d\n",j,fa[j],ch[j][0],ch[j][1],size[j],col[j]);
	for(int i=1,u,v;i<=q;i++){
		scanf("%s",str+1);
		if(str[1]=='u'){
			u=read();
			access(u,++now);
			if(!isroot(u))splay(u);
			lazy2[u]^=1;
		}
		else if(str[1]=='w'){
			u=read();
			write(que(u));putchar('\n');
		}
		else{
			u=read(),v=read();
			write((que(u)<que(v))?u:v);putchar('\n');
		}
//		for(int j=1;j<=n;j++)printf("%d ",que(j));putchar('\n');
//		for(int j=1;j<=n;j++)clear(j);
//		for(int j=1;j<=n;j++)printf("%d %d %d %d %d %d\n",j,fa[j],ch[j][0],ch[j][1],size[j],col[j]);
	}
}