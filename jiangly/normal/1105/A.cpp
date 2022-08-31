#include<bits/stdc++.h>
using namespace std;
int n,ans=1e9,t=1;
int a[1001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=100;++i){
		int res=0;
		for(int j=1;j<=n;++j){
			res+=min(min(abs(a[j]-i-1),abs(a[j]-i+1)),abs(a[j]-i));
		}
		if(res<ans){
			ans=res;
			t=i;
		}
	}
	printf("%d %d",t,ans);
	return 0;
}