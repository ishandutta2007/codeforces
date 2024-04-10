#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e5+9;
int n,a[M];
void work(){
	ll sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)a[i]=i;
	for(int i=1;i<n;++i){
		int t=n-i>i-1?n:1;
		swap(a[i],a[t]);
		sum+=1ll*(t-i)*(t-i);
	}
	printf("%lld\n",sum);
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	printf("\n%d\n",n-1);
	for(int i=n-1;i>=1;--i){
		int t=n-i>i-1?n:1;
		printf("%d %d\n",i,t);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}