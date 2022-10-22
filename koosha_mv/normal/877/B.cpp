#include <bits/stdc++.h>
#include<map>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
int a[9000],dp[3][9000],sa=0,mx,ta=0;
int main(){
	string s;cin>>s;
	if(s[0]=='a') a[0]++;
	else sa++,a[1]++;	
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[i-1]){
			sa++;
			a[sa]++;
		}
		else{
			a[sa]++;
		}}
	sa++;
	if(sa%2==1){
		a[sa]=0;
		sa++;}
	f(i,0,sa/2){
		dp[0][i]=dp[0][i-1]+a[i*2];
		dp[1][i]=max(dp[0][i],dp[1][i-1])+a[i*2+1];
		dp[2][i]=max(dp[2][i-1],dp[1][i-1])+a[i*2];
		mx=max(dp[0][i],max(dp[1][i],dp[2][i]));
	}
	cout<<mx;
}