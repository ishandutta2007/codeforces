#include<iostream>
using namespace std;
long long a[100003],b[100003],dp1[100002],dp2[100002];
int main(){
	long long n;
	cin>>n;
	for(long long i=2;i<=n+1;i++)cin>>a[i];
	for(long long i=2;i<=n+1;i++)cin>>b[i];
	for(long long i=2;i<=n+1;i++){
		dp1[i]=max(max(dp2[i-1]+a[i],dp1[i-1]),dp2[i-2]+a[i]);
		dp2[i]=max(max(dp1[i-1]+b[i],dp2[i]-1),dp1[i-2]+b[i]);
	}
	cout<<max(dp1[n+1],dp2[n+1]);}