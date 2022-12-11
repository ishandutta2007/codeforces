#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long now;
int main(){
	scanf("%d",&n);
	now=2;
	for (int i=1;i<=n;i++){
		long long k1=1ll*i*(i+1)*(i+1);
		long long k2=now/k1;
		long long k3=trunc(sqrt(k2));
		while (k3>=0&&1ll*k3*k3>=k2) k3--;
		while (1ll*k3*k3<k2) k3++; k3=max(k3,1ll);
	//	cout<<k2<<" "<<k3<<" "<<k1<<endl;
		k1*=k3*k3;
		printf("%I64d\n",k1-now);
		now=k3*i;
	}
	return 0;
}