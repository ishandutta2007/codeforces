#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans;
int a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	for(int i=1;i<n;++i){
		if(a[i]>a[i+1]){
			if(ans){
				printf("-1");
				return 0;
			}else{
				ans=i;
			}
		}
	}
	if(ans){
		if(a[n]>a[1]){
			printf("-1");
		}else{
			printf("%d",n-ans);
		}
	}else{
		printf("0");
	}
	return 0;
}