#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n;
int a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	if(n>3||n==3&&a[1]+a[3]!=2*a[2]){
		puts("-1");
	}else if(n==2&&(a[2]-a[1])%2==1){
		printf("%d\n",a[2]-a[1]);
	}else{
		printf("%d\n",(a[n]-a[1])/2);
	}
	return 0;
}