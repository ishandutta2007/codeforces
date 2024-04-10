#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int A[2000000];
int len=0,n,N=1001000;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); A[k1]++;
	}
	int ans=0;
	for (int i=0;i<=N;i++)
		if (A[i]){
			A[i+1]+=(A[i])/2; A[i]%=2;
			if (A[i]) ans++;
		}
	printf("%d\n",ans);
	return 0;
}