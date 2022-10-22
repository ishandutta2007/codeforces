#include <cstdio>
#include <algorithm>
const int Maxn=10000;
int n,k;
int a[Maxn+5];
int or_a[Maxn+5],and_a[Maxn+5];
int query_or(int x,int y){
	printf("or %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int query_and(int x,int y){
	printf("and %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=2;i<=n;i++){
		or_a[i]=query_or(1,i);
		and_a[i]=query_and(1,i);
		a[1]|=and_a[i];
	}
	int cur_val=query_and(2,3);
	for(int i=0;i<30;i++){
		if(((a[1]>>i)&1)||((cur_val>>i)&1)){
			continue;
		}
		bool flag=1;
		for(int j=2;j<=n;j++){
			if(((or_a[j]>>i)&1)==0){
				flag=0;
				break;
			}
		}
		if(flag){
			a[1]|=(1<<i);
		}
	}
	for(int i=2;i<=n;i++){
		a[i]=and_a[i];
		for(int j=0;j<30;j++){
			if((a[i]>>j)&1){
				continue;
			}
			if((or_a[i]>>j)&1){
				if(((a[1]>>j)&1)==0){
					a[i]|=(1<<j);
				}
			}
		}
	}
	std::sort(a+1,a+1+n);
	printf("finish %d\n",a[k]);
	return 0;
}