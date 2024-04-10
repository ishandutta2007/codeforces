#include <cstdio>
#include <algorithm>

int n,m,l[100001],num[100001];
long long sum;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",l+i),sum+=l[i];
	if(sum<n){
		puts("-1");
		return 0;
	}
	int last=n+1,pre=n;
	for(int i=1;i<=m;i++){
		--last;
		while(last-1>=sum&&last>=pre)--last;
		num[i]=std::max(last-l[i]+1,1);
		if(i>1&&num[i]+l[i]-1>=num[i-1]+l[i-1]-1){
			puts("-1");
			return 0;
		}
		sum-=l[i];
		pre=num[i];
	}
	if(num[m]!=1){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=m;i++)printf("%d ",num[i]);
}