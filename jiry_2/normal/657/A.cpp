#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,h,d;
int main(){
	scanf("%d%d%d",&n,&d,&h);
	if (d==h){
		if (n!=2&&d==1){
			printf("-1\n"); return 0;
		}
		for (int i=1;i<=h;i++) printf("%d %d\n",i,i+1);
		for (int i=h+2;i<=n;i++) printf("%d %d\n",2,i);
		return 0;
	}
	if (h*2<d){
		printf("-1\n"); return 0;
	}
	for (int i=1;i<=h;i++) printf("%d %d\n",i,i+1);
	int N=h,pre=1;
	for (int i=h+2;i<=d+1;i++){
		printf("%d %d\n",i,pre); pre=i;
	}
	for (int i=d+2;i<=n;i++) printf("%d %d\n",i,1);
	return 0;
}