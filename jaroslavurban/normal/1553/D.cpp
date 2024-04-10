#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// dp[N][2] == i chars done, smallest pointer to t, s.t. it has j parity

const int N=100100;
int dp[N][2];
string s,t;
int n,m;

int solvedp(int i,int j){
	if(~dp[i][j])return dp[i][j];
	dp[i][0]=INT_MAX;
	dp[i][1]=INT_MAX;
	if(i==1){
		for(int k=m-1;k>=0;--k)if(t[k]==s[i-1])dp[i][k&1]=k;
	}else{
		for(int it=0;it<2;++it){
			int k=solvedp(i-1,it);
			if(k==INT_MAX)continue;
			for(int l=k+1;l<m;l+=2)if(t[l]==s[i-1]){
				dp[i][l&1]=l;break;
			}
		}
	}
//	cerr<<"done "<<i<<" at pos "<<dp[i][0]<<" and "<<dp[i][1]<<endl;
	return dp[i][j];
}

void ProGamerMove(){
	cin>>t>>s;
	n=s.size(),m=t.size();
	for(int i=0;i<=n;++i)dp[i][0]=dp[i][1]=-1;
	int res=min(solvedp(n,0),solvedp(n,1));
	if(solvedp(n,!(m&1))!=INT_MAX)cout<<"YES\n";
	else cout<<"NO\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}