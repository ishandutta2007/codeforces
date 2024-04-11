#include<iostream>
using namespace std;
long long dp[100002],a[100001],x;
int main(){
	long long n,mx=0;cin>>n;
	for(long long i=0;i<n;i++){
		cin>>x;a[x]++;mx=max(mx,x);}
	dp[1]=a[1];
	dp[2]=max(a[2]*2,a[1]);
	for(long long i=3;i<mx+1;i++){
		dp[i]=max(dp[i-2]+(a[i]*i),dp[i-1]);
	}
	cout<<dp[mx];
}