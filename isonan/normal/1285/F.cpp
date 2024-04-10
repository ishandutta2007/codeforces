#include <cstdio>
#include <vector>
#include <algorithm>

int n,a[100001],stk[100001],top,d[100001],mu[100001],prime[100001];
bool pri[100001];
std::vector<int>dvs[100001],v[100001];
void add(int x,int y){
	for(int i=0;i<dvs[x].size();i++)
		d[dvs[x][i]]+=y;
}
int chk(int x){
	int tot=0;
	for(int i=0;i<dvs[x].size();i++)
		tot+=d[dvs[x][i]]*mu[dvs[x][i]];
	return tot;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	mu[1]=1;
	for(int i=2;i<=100000;i++){
		if(!pri[i])prime[++top]=i,mu[i]=-1;
		for(int j=1;j<=top&&i*prime[j]<=100000;j++){
			pri[i*prime[j]]=1;
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=100000;i++)
		for(int j=i;j<=100000;j+=i)
			dvs[j].push_back(i);
	for(int i=1;i<=n;i++)
		for(int j=0;j<dvs[a[i]].size();j++)
			v[dvs[a[i]][j]].push_back(a[i]);
	long long ans=0;
	for(int i=1;i<=100000;i++){
		std::sort(v[i].begin(),v[i].end());
		top=0;
		for(int j=v[i].size()-1;~j;--j){
			while(chk(v[i][j]/i))ans=std::max(ans,1ll*stk[top]*v[i][j]/i),add(stk[top]/i,-1),--top;
			add((stk[++top]=v[i][j])/i,1);
		}
		while(top){
			add(stk[top]/i,-1);
			--top;
		}
	}
	printf("%lld\n",ans);
}