#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[110000],n;
const int mo=10007;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	int ans=0;
	for (int i=1;i<=n;i++) ans=(ans+1ll*A[i]*A[n-i+1])%mo;
	printf("%d\n",ans);
}