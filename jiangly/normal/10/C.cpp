#include<bits/stdc++.h>
typedef long long ll;
int n;
ll sum;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=9;++i)
		for(int j=1;j<=9;++j)
			sum+=1ll*((n-1)/9+((n-1)%9+1>=i))*((n-1)/9+((n-1)%9+1>=j))*((n-1)/9+((n-1)%9+1>=(i*j-1)%9+1));
	for(int i=1;i<=n;++i)
		sum-=n/i;
	printf("%I64d\n",sum);
	return 0;
}