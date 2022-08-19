#include <bits/stdc++.h>

int head[40010],nxt[1000001],b[1000001],v[1000001],c[1000001],k=1,pre[1000010],S,T;
long long dis[1000001];
int map[201][201],n,m;
void push(int s,int t,int val,int cost){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
	c[k]=cost;
}
void link(int s,int t,int val,int cost){
//	printf("link %d %d %d %d\n",s,t,val,cost);
	push(s,t,val,cost);
	push(t,s,0,-cost);
}
int hash(int i,int j){
	return (i-1)*n+j;
}
int se[1000010];
int cmp(int a,int b){
	return dis[a]>dis[b]?a:b;
}
int node[40010],mxn;
void Build(int root,int l,int r){
	se[root]=l;
	if(l==r){
		node[l]=root;
		mxn=std::max(mxn,root);
		return;
	}
	Build(root<<1,l,(l+r)>>1);
	Build(root<<1|1,((l+r)>>1)+1,r);
}
bool get(){
	for(int i=S;i<=T+1;i++)dis[i]=-1e18;
	dis[S]=0;
	se[1]=S;
	for(;;){
		int now=se[1];
//		printf("%d %lld\n",now,dis[now]);
		if(now>T)break;
		se[node[now]]=T+1;
		for(int tem=node[now]>>1;tem;tem>>=1)
			se[tem]=cmp(se[tem<<1],se[tem<<1|1]);
		for(int i=head[now];i;i=nxt[i])
			if(v[i]&&dis[b[i]]<dis[now]+c[i]){
				dis[b[i]]=dis[now]+c[i];
//				printf("%d %d\n",now,b[i]);
				pre[b[i]]=i;
				if(b[i]>S&&b[i]<T){
					for(int tem=node[b[i]];tem;tem>>=1)
						se[tem]=cmp(se[tem],b[i]);
				}
			}
	}
//	putchar('*');
	return dis[T]!=-1e18;
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	long long ans=0;
	for(int i=1;i<n;i++)ans+=std::abs(map[i][1]-map[i+1][1]);
	for(int i=1;i<n;i++)ans+=std::abs(map[i][n]-map[i+1][n]);
	for(int i=1;i<n;i++)ans+=std::abs(map[1][i]-map[1][i+1]);
	for(int i=1;i<n;i++)ans+=std::abs(map[n][i]-map[n][i+1]);
	T=n*n+1;
	for(int i=2;i<n;i++)
		for(int j=2;j<n;j++)
			if(!map[i][j]){
				if(i==2){
					link(S,hash(i,j),1,map[i-1][j]);
					link(hash(i,j),T,1,-map[i-1][j]);
				}
				if(i==n-1){
					link(S,hash(i,j),1,map[i+1][j]);
					link(hash(i,j),T,1,-map[i+1][j]);
				}
				if(j==2){
					link(S,hash(i,j),1,map[i][j-1]);
					link(hash(i,j),T,1,-map[i][j-1]);
				}
				if(j==n-1){
					link(S,hash(i,j),1,map[i][j+1]);
					link(hash(i,j),T,1,-map[i][j+1]);
				}
				if(!map[i+1][j]){
					link(hash(i,j),hash(i+1,j),1,0);
					v[k]=1;
//					link(hash(i+1,j),hash(i,j),1,0);
				}
				if(!map[i][j+1]){
					link(hash(i,j),hash(i,j+1),1,0);
					v[k]=1;
//					link(hash(i,j+1),hash(i,j),1,0);
				}
			}
	Build(1,S,T);
//	return 0;
	while(get()){
		int tem=T;
		if(dis[T]<0)break;
		while(tem!=S){
			--v[pre[tem]];
			++v[pre[tem]^1];
			tem=b[pre[tem]^1];
		}
		ans+=dis[T];
	}
	printf("%lld\n",ans);
}