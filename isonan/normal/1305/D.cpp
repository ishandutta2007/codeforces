#include <cstdio>
#include <cstdlib>
#include <algorithm> 

int n,x,y,head[10010],nxt[20010],b[20010],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int root,full,mx[10010],size[1010],stk[10010],top;
bool vis[10010];
int query(int u,int v){
	printf("? %d %d\n",u,v);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
void getroot(int x,int f){
	mx[x]=0,size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]])getroot(b[i],x),size[x]+=size[b[i]],mx[x]=std::max(mx[x],size[b[i]]);
	mx[x]=std::max(mx[x],full-size[x]);
	if(mx[x]<mx[root])root=x;
}
void getdis(int x,int f){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(!vis[b[i]]&&b[i]!=f)getdis(b[i],x),size[x]+=size[b[i]];
}
void solve(int rt){
	vis[rt]=1;
	top=0;
	for(int i=head[rt];i;i=nxt[i])
		if(!vis[b[i]])stk[++top]=b[i],getdis(b[i],0);
	int ans=0;
	stk[top+1]=rt;
	for(int i=1;i<=top;i+=2){
		int v=query(stk[i],stk[i+1]);
		if(v!=rt){
			mx[root=0]=full=size[v];
			getroot(v,0);
			solve(root);
			break;
		}
	}
	printf("! %d\n",rt);
	fflush(stdout);
	exit(0);
}
int d[1001];
void del(int x,int f){
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(!vis[b[i]]&&b[i]!=f)del(b[i],x);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		push(x,y);
		push(y,x);
		++d[x];++d[y];
	}
	for(;;){
		int p=-1;
		for(int i=1;i<=n;i++)
			if(d[i]>=2&&!vis[i])p=i;
		if(!~p){
			int w=0,v=0;
			for(int i=1;i<=n;i++)
				if(!vis[i]){
					if(w)v=i;
					else w=i;
				}
			if(v){
				printf("! %d\n",query(w,v));
				fflush(stdout);
				exit(0);
			}
			break;
		}
		int w=0,v=0;
		for(int i=head[p];i;i=nxt[i])
			if(!vis[b[i]]){
				if(w)v=b[i];
				else w=b[i];
			}
		int x=query(w,v);
		if(x==p)del(w,p),del(v,p),d[p]-=2;
		else if(x==w)del(p,w),--d[w];
		else del(p,v),--d[v];
	}
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					printf("! %d\n",i);
					fflush(stdout);
					return 0;
				}
			}
}