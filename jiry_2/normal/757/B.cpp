#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[110000],n;
int main(){
	scanf("%d",&n); int num=0;
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); A[k1]++; num=max(num,k1);
	}
	int ans=1;
	for (int i=2;i<=num;i++){
		int k1=0;
		for (int j=i;j<=num;j+=i) k1+=A[j];
		ans=max(ans,k1);
	}
	printf("%d\n",ans);
}