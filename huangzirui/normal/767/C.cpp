#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=1000005;
int n,ps,tot,rt;
int a[maxn],pos[maxn],sum[maxn];
vector<int>v[maxn];
void dfs(int x,int last){
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y==last)
			continue;
		dfs(y,x),sum[x]+=sum[y];
	}
	sum[x]+=a[x];
	if(sum[x]==tot)
		pos[++ps]=x,sum[x]=0;
}
int main(){
	scanf("%d",&n); 
	for(int i=1,x;i<=n;i++){
		scanf("%d%d",&x,&a[i]);
		if(x==0)
			rt=i;
		else v[x].push_back(i),v[i].push_back(x);
		tot+=a[i];
	}
	if(tot%3){
		puts("-1");
		return 0;
	}
	tot/=3,dfs(rt,0);
	if(ps>=3)
		printf("%d %d\n",min(pos[1],pos[2]),max(pos[1],pos[2]));
	else puts("-1");
	return 0;
}