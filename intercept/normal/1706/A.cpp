#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
const int M=109;
int dp[M];
void work(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i)dp[i]=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		if(x>m+1-x)x=m+1-x;
		if(dp[x]==0)dp[x]=1;
		else dp[m+1-x]=1;
	}
	for(int i=1;i<=m;++i)putchar('A'+(!dp[i]));
	puts("");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}