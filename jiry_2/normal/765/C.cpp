#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int K,a,b;
int main(){
	scanf("%d%d%d",&K,&a,&b);
	int ans=a/K+b/K;
	int k1=a%K,k2=b%K;
	if (k1&&b<K) ans=-1;
	if (k2&&a<K) ans=-1;
	cout<<ans<<endl;
	return 0;
}