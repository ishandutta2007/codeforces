#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,T;
struct Splay{
	int ch[2],fa;bool rev;
	int col,paint,sz;
}t[N];
int cnt,null=0;
inline bool isroot(int x){return t[t[x].fa].ch[1]!=x&&t[t[x].fa].ch[0]!=x;}
inline bool son(int x){return t[t[x].fa].ch[1]==x;}

inline void pushup(int x){t[x].sz=t[t[x].ch[1]].sz+t[t[x].ch[0]].sz+1;}
inline void pushdown(int x){
	if(t[x].rev){
		swap(t[x].ch[0],t[x].ch[1]);
		if(t[x].ch[0])t[t[x].ch[0]].rev^=1;
		if(t[x].ch[1])t[t[x].ch[1]].rev^=1;
		t[x].rev=0;
	}
	if(t[x].paint){
		t[x].col=t[x].paint;
		if(t[x].ch[1])t[t[x].ch[1]].paint=t[x].paint;
		if(t[x].ch[0])t[t[x].ch[0]].paint=t[x].paint;
		t[x].paint=0;
	}
}
inline void pushnow(int x){
	if(!isroot(x))pushnow(t[x].fa);
	pushdown(x);
}

inline void rotate(int x){
	int f=t[x].fa,g=t[t[x].fa].fa;
	bool a=son(x),b=son(x)^1;
	if(!isroot(f))t[g].ch[son(f)]=x;
	t[x].fa=g;
	t[t[x].ch[b]].fa=f;t[f].ch[a]=t[x].ch[b];
	t[x].ch[b]=f;t[f].fa=x;
	pushup(f);pushup(x);
}

inline void splay(int x){
	pushnow(x);
	while(!isroot(x)){
		int f=t[x].fa;
		if(!isroot(f)){
			if(son(x)^son(f))rotate(x);
			else rotate(f);
		}
		rotate(x);
	}
}
#define lowbit(x) (x&(-x))
struct fenwick{
	int t[N<<1],n;
	void set(int _n){n=_n;}
	inline void add(int x,int y){
		for(;x<=n;x+=lowbit(x))t[x]+=y;
	}
	inline int qry(int x){
		int ans=0;for(;x;x-=lowbit(x))ans+=t[x];
		return ans;
	}
}BIT;

inline void access(int x,int id){//and make root
	int tmp=null;
	int d=x;
	while(x){
		splay(x);
		t[x].ch[1]=tmp;
		pushup(x);
		int SZ=t[x].sz-t[t[x].ch[1]].sz;
		BIT.add(t[x].col,-SZ);
		//
		BIT.add(id,SZ);
		tmp=x; x=t[x].fa;
	}
	splay(d);
	t[d].paint=id;
	t[d].rev^=1;
}
int anc[N][20];
int hed[N],to[N<<1],nxt[N<<1],ecnt,deg[N];
int dep[N];
inline void adde(int u,int v){
	++ecnt;to[ecnt]=v,nxt[ecnt]=hed[u];hed[u]=ecnt;
}
inline void dfs(int x,int pre){
	dep[x]=dep[pre]+1;
	t[x].fa=pre; anc[x][0]=pre; for(int i=1;1<<i<=n;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		deg[x]++;
		dfs(v,x);
	}
}
priority_queue<int,vector<int>,greater<int> > heap;

inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=18;~i;i--)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	if(x==y)return x;
	for(int i=18;~i;i--)if(anc[x][i]^anc[y][i]) x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
int start[N<<1];
char opt[20];

inline int qry(int x){
	splay(x);
	int sd=BIT.qry(t[x].col-1);
	int ca=lca(start[t[x].col],x);
	int len=dep[start[t[x].col]]+dep[x]-dep[ca]*2+1;
	return sd+len;
}

int main()
{
	cin>>n>>T;
	BIT.set(n+T+1);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v);adde(v,u);
	}
	dfs(n,0);
	for(int i=1;i<=n;i++)if(deg[i]==0)heap.push(i);
	int time=0;
	while(!heap.empty()){
		int u=heap.top();heap.pop();
		//cout<<u<<endl;
		t[u].col=++time;
		t[u].sz=1;
		BIT.add(time,1);
		deg[anc[u][0]]--;
		start[time]=u;
		if(u!=n&&!deg[anc[u][0]])heap.push(anc[u][0]);
	}
	int final=n;
	while(T--){
		scanf("%s",opt+1);
		if(opt[1]=='u'){//up
			start[++time]=final;
			int id;scanf("%d",&id);
			final=id;
			access(id,time);
		}
		else if(opt[1]=='c'){//compare
			int x,y;scanf("%d%d",&x,&y);
			printf("%d\n",qry(x)<qry(y)?x:y);
		}
		else {//when
			int x;scanf("%d",&x);
			printf("%d\n",qry(x));
		}
	}
	
}