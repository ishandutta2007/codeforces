#include<bits/stdc++.h>
using namespace std;
const int N=200005;
map<int,int>MP;
struct node{
	int a,b;
	inline node(){}
	inline node(int a,int b):a(a),b(b){}
	bool operator<(node x)const{
		return a<x.a;
	}
}nod[N];
int a[N],nxt[N],fa[N],rt[N],sz[N],b[N];
int find(int v){return fa[v]==0?v:fa[v]=find(fa[v]);}
int main(){
//	freopen("7.in","r",stdin);
	int n,m,i,t=0,x,y,sum;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)b[i]=a[i];
	sort(b+1,b+n+1);
	for(i=1;i<=n;++i)if(a[i]!=b[i]){a[++t]=a[i];b[t]=i;nod[t]=node(a[t],t);}
//	for(i=1;i<=t;++i)printf("Node #%d: %d %d\n",i,a[i],b[i]);
	if(t> m){printf("-1");return 0;}
	if(t==0){printf( "0");return 0;}
	sort(nod+1,nod+(n=t)+1);
	for(i=1;i<=n;++i)nxt[nod[i].b]=i;
	for(i=1;i<=n;++i)if(fa[i]==0)
		for(x=nxt[i];x!=i;x=nxt[x])fa[x]=i;
//	for(i=1;i<=n;++i)printf("Node #%d: a=%d nxt=%d fa=%d oid=%d\n",i,a[i],nxt[i],fa[i],b[i]);printf("\n");
	for(i=1;i<=n;++i){
		t=MP[a[i]];
		if(t!=0){
			x=find(i);
			y=find(t);
			if(x!=y){fa[x]=y;swap(nxt[i],nxt[t]);}
		}
		MP[a[i]]=i;
	}
//	for(i=1;i<=n;++i)printf("Node #%d: a=%d nxt=%d fa=%d oid=%d\n",i,a[i],nxt[i],fa[i],b[i]);printf("\n");
	t=0;
	for(i=1;i<=n;++i)if(fa[i]==0)rt[++t]=i;
	for(i=1;i<=n;++i)++sz[find(i)];
	if(t==1||m<=n+2){
		printf("%d",t);
		for(i=  1;i<=t;++i){
			x=rt[i];
			printf("\n%d\n%d",sz[x],b[x]);
			for(y=nxt[x];y!=x;y=nxt[y])printf(" %d",b[y]);
		}
	}else{
		m=min(m-n,t);
		sum=0;
		for(i=  1;i<=m;++i)sum+=sz[rt[i]];
		printf("%d\n%d\n",t-m+2,sum);
		for(i=  1;i<=m;++i){
			x=rt[i];
			printf("%d ",b[x]);
			for(y=nxt[x];y!=x;y=nxt[y])printf("%d ",b[y]);
		}
		printf("\n%d\n",m);
		for(i=m  ;i>=1;--i)printf("%d ",b[rt[i]]);
		for(i=m+1;i<=t;++i){
			x=rt[i];
			printf("\n%d\n%d",sz[x],b[x]);
			for(y=nxt[x];y!=x;y=nxt[y])printf(" %d",b[y]);
		}
	}
	return 0;
}