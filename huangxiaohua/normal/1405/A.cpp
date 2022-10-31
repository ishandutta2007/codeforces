#include<bits/stdc++.h>
using namespace std;

int i,j,n,t,a[100500];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=n;i>=1;i--){
			printf("%d ",a[i]);
		}puts("");
	}
}