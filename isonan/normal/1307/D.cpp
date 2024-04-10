#include <cstdio>
#include <cstring> 
#include <algorithm>

int n,m,K,head[200001],nxt[400001],b[400001],k,a[200001];
int dis1[200001],disn[200001],q[200001],h,t,c[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void getdis(int x,int *dis){
	h=t=0;
	for(int i=1;i<=n;i++)dis[i]=-1;
	dis[x]=0;
	q[++t]=x;
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i])
			if(!~dis[b[i]]){
				dis[b[i]]=dis[q[h]]+1;
				q[++t]=b[i];
			}
	}
}
void update(int ind,int num){
	for(;ind;ind-=ind&-ind)c[ind]=std::max(c[ind],num);
}
int query(int ind){
	if(ind<=0)ind=1;
	int tot=-0x7f7f7f7f;
	for(;ind<=n;ind+=ind&-ind)tot=std::max(tot,c[ind]);
	return tot;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=K;i++)scanf("%d",a+i);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	getdis(1,dis1);
	getdis(n,disn);
	int ans=-0x7f7f7f7f;
	memset(c,-0x7f7f7f7f,sizeof c);
	for(int i=1;i<=K;i++){
		int l=0,r=n,mid,fin=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(query(mid-dis1[a[i]]-1)>=mid-disn[a[i]]-1)fin=mid,l=mid+1;
			else r=mid-1;
		}
		ans=std::max(ans,fin);
		update(disn[a[i]],dis1[a[i]]);
	}
	printf("%d\n",std::min(ans,disn[1]));
}