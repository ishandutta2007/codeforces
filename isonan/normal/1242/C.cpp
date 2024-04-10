#include <cstdio>
#include <vector> 
#include <map>

std::vector<int>num[16];
long long sum[16],tot;
std::map<int,int>map;
int pre[1000001],v[1000001],cnt,bel[1000001],ans[100001],f[100001],Pre[100001];
int n,stk[16],top,p[16],V[16];
bool vis[16];
void Do(int x){
	if(vis[bel[x]])return;
	vis[bel[x]]=1;
	p[bel[pre[x]]]=bel[x];
	V[bel[x]]=v[x];
	Do(pre[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,tem;i<=n;i++){
		scanf("%d",&tem);
		num[i].resize(tem);
		for(int j=0;j<tem;j++){
			++cnt;
			scanf("%d",v+cnt);
			num[i][j]=cnt;
			bel[cnt]=i;
			map[v[cnt]]=cnt;
			sum[i]+=v[cnt];
			tot+=v[cnt];
		}
	}
	if(tot%n){
		puts("No");
		return 0;
	}
	tot/=n;
	for(int i=1;i<=cnt;i++){
		if(!map.count(v[i]-sum[bel[i]]+tot)){
			pre[i]=-1;
			continue;
		}
		pre[i]=map[v[i]-sum[bel[i]]+tot];
		if(bel[pre[i]]==bel[i]&&pre[i]!=i)pre[i]=-1; 
	}
	for(int i=1;i<=cnt;i++){
		int tem=i;
		for(int j=1;j<=n;j++)vis[j]=0;
		bool cando=1;
		int stat=0;
		do{
			if(tem==-1)cando=0;
			if(vis[bel[tem]]){
				cando=0;
				break;
			}
			vis[bel[tem]]=1;
			stat|=(1<<(bel[tem]-1));
			tem=pre[tem];
		}while(tem!=i);
		if(cando)f[stat]=i;
	}
	ans[0]=1;
	for(int i=0;i<(1<<n);i++){
		if(f[i]){
			ans[i]=1;
			Pre[i]=0;
			continue;
		}
		for(int j=i;j;j=(j-1)&i)
			if(ans[j]&&f[i^j]){
				ans[i]=1;
				Pre[i]=j;
				break;
			}
	}
	for(int i=1;i<=n;i++)vis[i]=0;
	if(ans[(1<<n)-1]){
		puts("Yes");
		int stat=(1<<n)-1;
		while(stat){
			int tem=stat^Pre[stat];
			Do(f[tem]);
			stat=Pre[stat];
		}
		for(int i=1;i<=n;i++)printf("%d %d\n",V[i],p[i]);
	}else 
	puts("No");
}