#include <cstdio>
#include <utility>
#include <cstring>
#include <algorithm>

int n,k,d[51];
int val[100001],cnt;
int hsh[51][51];
std::pair<int,int>edg[100001];
bool vis[100001];
int q[10000001],h,t;
bool inq[100001];
int stk[51],top,pos[100001];
bool Can[51][100001];
int f[100001];
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b)f[a]=b;
}
int ed[100001],vd[100001],D[51],pre[100001];
bool check(int x,int y){
	bool ans=1;
	--D[edg[y].first];
	--D[edg[y].second];
	if((++D[edg[x].first])>d[edg[x].first])ans=0;
	if((++D[edg[x].second])>d[edg[x].second])ans=0;
	--D[edg[x].first];
	--D[edg[x].second];
	++D[edg[y].first];
	++D[edg[y].second];
	return ans;
}
struct edge{
	int u,v,w;
}Edg[10001];
int cnt2;
bool vis2[10001];
int calc(){
	for(int i=1;i<=k;++i)f[i]=0;
	for(int i=1;i<=cnt2;++i){
		if(!vis2[i])continue;
		int u=find(Edg[i].u),v=find(Edg[i].v);
		if(u!=v){
			f[u]=v;
		}
		else return 0x7f7f7f7f;
	}
	int fd=1,ans=0;
	for(int i=1;i<=cnt2;++i){
		if(vis2[i])--d[Edg[i].u],--d[Edg[i].v],++fd,ans+=Edg[i].w;
	}
	bool Ans=1;
	for(int i=1;i<=k;++i)if(d[i]<0)Ans=0;
	if(!Ans){
		for(int i=1;i<=cnt2;++i){
			if(vis2[i])++d[Edg[i].u],++d[Edg[i].v];
		}
		return 0x7f7f7f7f;
	}
	memset(vis,0,sizeof vis);
	for(;fd<n;++fd){
		h=t=0;
		top=0;
		for(int i=1;i<=n;++i)D[i]=0;
		for(int i=1;i<=cnt;++i)
			if(vis[i]){
				stk[pos[i]=++top]=i;
				++D[edg[i].first];
				++D[edg[i].second];
			}
		for(int i=0;i<=top;++i){
			for(int i=1;i<=n;++i)f[i]=0;
			for(int i=1;i<=cnt2;++i)if(vis2[i])merge(Edg[i].u,Edg[i].v);
			for(int j=1;j<=top;++j)if(j!=i)merge(edg[stk[j]].first,edg[stk[j]].second);
			for(int j=1;j<=cnt;++j)
				if(!vis[j])
					Can[i][j]=(find(edg[j].first)!=find(edg[j].second));
		}
		for(int i=1;i<=cnt;++i)ed[i]=vd[i]=0x7f7f7f7f,inq[i]=0;
		for(int i=1;i<=cnt;++i)
			if(!vis[i]&&Can[0][i])q[++t]=i,ed[i]=0,vd[i]=val[i],inq[i]=1,pre[i]=0;
		while(h<t){
			inq[q[++h]]=0;
			if(vis[q[h]]){
				int u=pos[q[h]];
				for(int i=1;i<=cnt;++i)
					if(!vis[i]&&Can[u][i]&&((ed[i]>ed[q[h]]+1&&vd[i]==vd[q[h]]+val[i])||vd[i]>vd[q[h]]+val[i])){
						ed[i]=ed[q[h]]+1;
						vd[i]=vd[q[h]]+val[i];
						pre[i]=q[h];
						if(!inq[i]){
							inq[i]=1;
							q[++t]=i;
						}
					}
			}
			else{
				for(int j=1;j<=top;++j){
					int i=stk[j];
					if(check(q[h],i)&&((ed[i]>ed[q[h]]+1&&vd[i]==vd[q[h]]-val[i])||vd[i]>vd[q[h]]-val[i])){
						ed[i]=ed[q[h]]+1;
						vd[i]=vd[q[h]]-val[i];
						pre[i]=q[h];
						if(!inq[i]){
							inq[i]=1;
							q[++t]=i;
						}
					}
				}
			}
		}
		int d=0x7f7f7f7f,v=0x7f7f7f7f,p=0;
		for(int i=1;i<=cnt;++i)
			if(!vis[i]&&check(i,0)){
				if((vd[i]<v||(vd[i]==v&&ed[i]<d))){
					v=vd[i];
					d=ed[i];
					p=i;
				}
			}
		if(!p){
			ans=0x7f7f7f7f;
			break;
		}
		int tem=p;
		while(tem){
			vis[tem]^=1;
			tem=pre[tem];
		}
		ans+=v;
		// for(int i=1;i<=cnt;++i)
		// 	if(vis[i])printf("(%d %d)",edg[i].first,edg[i].second);putchar('\n');
	}
	for(int i=1;i<=cnt2;++i){
		if(vis2[i])++d[Edg[i].u],++d[Edg[i].v];
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)scanf("%d",d+i);
	for(int i=k+1;i<=n;++i)d[i]=n;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			if(j<=k){
				Edg[++cnt2]=(edge){i,j,0};
				scanf("%d",&Edg[cnt2].w);
			}
			else{
				hsh[i][j]=++cnt;
				scanf("%d",&val[cnt]);
				edg[cnt]=std::make_pair(i,j);
			}
		}
	int ans=0x7f7f7f7f;
	for(int i=0;i<(1<<cnt2);++i){
		// printf("%d\n",i);
		for(int j=1;j<=cnt2;++j)vis2[j]=(i&(1<<(j-1)))!=0;
		ans=std::min(ans,calc());
	}
	printf("%d\n",ans);
}