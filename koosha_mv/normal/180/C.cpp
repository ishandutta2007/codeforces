#include<iostream>
using namespace std;
int dp[100009],mn=0;
int main(){
	string s;int u=0;cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='A' && s[i]<='Z')
			u++;
	}
	dp[0]=u;mn=u;
	for(int i=0;i<s.size();i++){
		dp[i+1]=dp[i]+1;
		if(s[i]>='A' && s[i]<='Z')
			dp[i+1]=dp[i]-1;
		mn=min(mn,dp[i+1]);
	}
	cout<<mn;
}