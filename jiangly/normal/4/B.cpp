//Time Complexity : O(N)
//Space Complexity : O(N)
#include<bits/stdc++.h>
using namespace std;
const int N=30;
int main(){
	int n,sum,l=0,r=0;
	scanf("%d%d",&n,&sum);
	int a[N+1],b[N+1];
	for(int i=1;i<=n;++i){
		scanf("%d%d",a+i,b+i);
		l=l+a[i];
		r=r+b[i];
	}
	if(sum<l||sum>r){
		printf("NO\n");
	}else{
		printf("YES\n");
		for(int i=1;i<=n;++i){
			int d=min(sum-l,b[i]-a[i]);
			a[i]=a[i]+d;
			l=l+d;
		}
		for(int i=1;i<=n;++i){
			printf("%d ",a[i]);
		}
	}
	return 0;
}