#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=100005;
int n;
long long ans;
string s;
int cnt[27],suf[maxn][27];
long long res[27][27];
int main(){
	cin>>s,n=s.size();
	for(int i=n;i>=1;i--){
		int v=s[i-1]-96;
		for(int j=1;j<=26;j++)
			suf[i][j]=suf[i+1][j];
		suf[i][v]++;
	}
	for(int i=1;i<=26;i++)
		ans=max(ans,1ll*suf[1][i]);
	for(int i=1;i<n;i++){
		int v=s[i-1]-96;
		for(int j=1;j<=26;j++)
			res[v][j]+=suf[i+1][j];
	}
	for(int i=1;i<=26;i++)
		for(int j=1;j<=26;j++)
			ans=max(ans,res[i][j]);
	printf("%lld\n",ans);
	return 0;
}