#include<bits/stdc++.h>
using namespace std;
int dp[500009][26],e=1e6,mn=e;
int main(){
	int mnn,a,n,k;string s,s1="";cin>>n>>k>>s;
	for(int p=0;p<n;p++){
		for(int i=0;i<k;i++){
			dp[p][i]=e;
			for(int j=0;j<k;j++){
				if(j!=i){
					dp[p][i]=min(dp[p][i],dp[p-1][j]+1);
				}
			}
		}
		dp[p][s[p]-'A']--;
	}
	for(int i=0;i<k;i++){
		mn=min(mn,dp[n-1][i]);
	}cout<<mn<<endl;
	int gh=27;
	for(int i=n-1;i>=0;i--){
		mn=e;
		for(int j=0;j<k;j++){
			if(dp[i][j]<mn && j!=gh){mn=dp[i][j],a=j;}
		}
		s1+=char(int('A')+a);
		gh=a;
	}
	reverse(s1.begin(),s1.end());
	cout<<s1;
}