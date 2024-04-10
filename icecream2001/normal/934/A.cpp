#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long
using namespace std;
int n,m;
LL t=-1,k,inf=1000000001;
LL a[100],b[100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%I64d",&b[i]);
	t=t*inf*inf;k=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]*b[j]>t){
				t=a[i]*b[j];k=i;
			}
		}
	}
	t=-1;t=t*inf*inf;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i!=k&&b[j]*a[i]>t) t=b[j]*a[i];
		}
	}
	printf("%I64d\n",t);
	return 0;
}