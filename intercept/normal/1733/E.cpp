#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=5009;
const int S=1<<9;
int n,m,num;
ll dp[129][129],p[129][129];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		ll k,x,y;
		cin>>k>>x>>y;
		memset(dp,0,sizeof(dp));
		memset(p,0,sizeof(p));
		dp[0][0]=k-x-y+1;
		if(dp[0][0]<=0){
			cout<<"NO\n";
			continue;
		}
		p[0][0]=k-x-y;
		for(int i=0;i<=x;++i){
			for(int j=0;j<=y;++j){
				dp[i][j+1]+=(dp[i][j]+1)/2;
				dp[i+1][j]+=(dp[i][j])/2;
				p[i][j+1]+=(p[i][j]+1)/2;
				p[i+1][j]+=(p[i][j])/2;
			}
		}
		cout<<(dp[x][y]>p[x][y]?"YES":"NO")<<"\n";
	}
	return 0;
}
/*
1
5 1 3
0 0 0
2 4 5
2 0 2
1547748756 100 111

*/