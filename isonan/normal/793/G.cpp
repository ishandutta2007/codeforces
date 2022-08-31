#include <cstdio>
#include <cstring>
#include <algorithm>

int mx[2000001];
struct line{
	int x,l,r,ord;
}num[600001];
int n,Q;
bool cmp(line a,line b){
	return a.x<b.x||(a.x==b.x&&a.ord>b.ord);
}
int head[200001],nxt[4000001],b[4000001],v[4000001],k=1,S,T,cnt,edge[2][200001],time[200001],p[200001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void link(int s,int t,int val=0x7f7f7f7f){
//	printf("%d %d\n",s,t);
	push(s,t,val);
	push(t,s,0);
}
void pushup(int root){
	if(time[root<<1]==time[root<<1|1])time[root]=time[root<<1];
	else time[root]=-1;
}
void build(int root,int l,int r){
	if(l==r){
		edge[0][root]=l;
		edge[1][root]=l+n;
		time[root]=1;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	edge[0][root]=++cnt;
	link(edge[0][root<<1],edge[0][root]);
	link(edge[0][root<<1|1],edge[0][root]);
	edge[1][root]=++cnt;
	link(edge[1][root],edge[1][root<<1]);
	link(edge[1][root],edge[1][root<<1|1]);
	pushup(root);
}
void addedge(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r)return link(x,edge[1][root]);
	addedge(root<<1,l,(l+r)>>1,el,er,x);
	addedge(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
void spread(int root){
	if(~time[root])time[root<<1]=time[root<<1|1]=time[root];
}
void del(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r&&~time[root]){
		addedge(1,1,n,time[root],x-1,edge[0][root]);
		time[root]=0x7f7f7f7f;
		return;
	}
	spread(root);
	del(root<<1,l,(l+r)>>1,el,er,x);
	del(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	pushup(root);
}
void clear(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		time[root]=x;
		return;
	}
	spread(root);
	clear(root<<1,l,(l+r)>>1,el,er,x);
	clear(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	pushup(root);
}
int dis[2000001],q[2000001],h,t;
bool bfs(){
	for(int i=0;i<=cnt;i++)dis[i]=-1;
	h=t=0;
	q[++t]=S;
	dis[S]=0;
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i])
			if(v[i]&&!~dis[b[i]]){
				dis[b[i]]=dis[q[h]]+1;
				q[++t]=b[i];
				if(b[i]==T)return 1;
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if(x==T||!flow)return flow;
	int used=0;
	for(int i=p[x];i;i=nxt[i])
		if(v[i]&&dis[b[i]]==dis[x]+1){
			int w=dfs(b[i],std::min(flow-used,v[i]));
			v[i]-=w;
			v[i^1]+=w;
			if(w)p[x]=i;
			used+=w;
			if(used==flow)return used;
		}
	if(!used)dis[x]=-1;
	return used;
}
void debug(int root,int l,int r){
	printf("debug %d %d %d %d\n",root,l,r,time[root]);
	if(l==r)return;
	spread(root);
	debug(root<<1,l,(l+r)>>1);
	debug(root<<1|1,((l+r)>>1)+1,r);
}
void debug(int x,int o){
//	if(x>n&&x<=(n<<1))printf("con %d %d\n",o,x-n);
	for(int i=head[x];i;i=nxt[i])
		if(v[i])debug(b[i],o);
}
int main(){
	scanf("%d%d",&n,&Q);
	T=cnt=(n<<1)+1;
	for(int i=1;i<=n;i++)link(S,i,1),link(i+n,T,1);
//	return 0;
	for(int i=1,x1,y1,x2,y2;i<=Q;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		num[(i<<1)-1]=(line){x1,y1,y2,1};
		num[(i<<1)  ]=(line){x2,y1,y2,-1};
	}
	std::sort(num+1,num+(Q<<1)+1,cmp);
	build(1,1,n);
	for(int i=1;i<=(Q<<1);i++){
		if(num[i].ord==1)del(1,1,n,num[i].l,num[i].r,num[i].x);
		else clear(1,1,n,num[i].l,num[i].r,num[i].x+1);
//		debug(1,1,n);
	}
	del(1,1,n,1,n,n+1);
//	for(int i=1;i<=n;i++)debug(i,i);
	int ans=0;
	while(bfs()){
		memcpy(p,head,sizeof p);
		ans+=dfs(S,0x7f7f7f7f);
//		for(int i=1;i<=k;i+=2)printf("%d %d %d\n",b[i],b[i^1],v[i]);
	}
	printf("%d\n",ans);
}