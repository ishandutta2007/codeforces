#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll ans,n,a[300009],sa=0,dp[10001];
string s;
int main(){
	a[0]=1;
	cin>>n>>s;
	f(i,1,n){
		if(s[i]==s[i-1]) a[sa]++;
		else{sa++;a[sa]++;}}
	ans+=a[1];
	f(i,1,sa+1) ans+=(a[i-1]-1)+a[i+1];
	cout<<n*(n-1)/2-ans;
}