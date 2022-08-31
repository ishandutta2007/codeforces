#include <cstdio>
#include <algorithm>

struct point{
	int v,ord;
}se[500001];
bool cmp(point a,point b){
	return a.v<b.v;
}
int n,m;
int head[500001],nxt[2000001],b[2000001],k,v[500001],cnt[500001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	for(int i=1;i<=n;i++)scanf("%d",v+i);
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=nxt[j]){
			if(v[b[j]]==v[i]){
				puts("-1");
				return 0;
			}
			cnt[v[b[j]]]=1;
		}
		for(int j=1;j<v[i];j++)if(!cnt[j]){
			puts("-1");
			return 0;
		}
		
		for(int j=head[i];j;j=nxt[j]){
			if(v[b[j]]==v[i]){
				puts("-1");
				return 0;
			}
			cnt[v[b[j]]]=0;
		}
	}
	for(int i=1;i<=n;i++)se[i]=(point){v[i],i};
	std::sort(se+1,se+n+1,cmp);
	for(int i=1;i<=n;i++)printf("%d ",se[i].ord);
}