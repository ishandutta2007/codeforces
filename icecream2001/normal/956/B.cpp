#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 100050
using namespace std;
int n,u;
int a[N];
double ans=0.0;
int main(){
	scanf("%d%d",&n,&u);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool flag=0;
	for(int i=1;i<=n-2;i++){
		if(a[i+2]-a[i]<=u) {
			flag=1;
			break;
		}
	}
	if(!flag){
		printf("-1\n");return 0;
	}
	for(int i=n-2,j=n;i>=1;i--){
		while(a[j]-a[i]>u) j--;
		if(j>=i+2){
			if((double)(a[j]-a[i+1])/(double)(a[j]-a[i])>ans)
				ans=(double)(a[j]-a[i+1])/(double)(a[j]-a[i]);
		}
	}
	printf("%0.10lf\n",ans);
	return 0;
}