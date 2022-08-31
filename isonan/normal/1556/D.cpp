#include <cstdio>
#include <algorithm>

int v1[10001],v2[10001],n,k;
int a[10001];
int query(int ty,int i,int j){
	if(ty==1)printf("or ");
	else printf("and ");
	printf("%d %d\n",i,j);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int Xor(int i,int j){
	return v1[i]^v2[i]^v1[j]^v2[j];
}
bool vis[31];
int ans[10001];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=2;i<=n;++i)v1[i]=query(1,1,i);
	for(int i=2;i<=n;++i)v2[i]=query(2,1,i);
	int sure=0;
	for(int i=0;i<31;++i){
		for(int j=2;j<=n;++j)
			if((v2[j]&(1<<i))){
				ans[1]|=1<<i;
				sure|=1<<i;
				break;
			}
			else if(!(v1[j]&(1<<i))){
				sure|=1<<i;
				break;
			}
	}
	int v3=query(1,2,3);
	for(int i=0;i<31;++i)
		if(!(sure&(1<<i))){
			if(v3&(1<<i));
			else ans[1]|=1<<i;
		}
	for(int i=2;i<=n;++i)ans[i]=ans[1]^v1[i]^v2[i];
	std::sort(ans+1,ans+n+1);
	printf("finish %d\n",ans[k]);
	fflush(stdout);
}