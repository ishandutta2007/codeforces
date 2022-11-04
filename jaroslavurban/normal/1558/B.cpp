#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=4000100;
ll dp[N],pref[N];
int n,m;

int query(int l,int r){r=min(r,N-1);
	return (pref[l]-pref[r])%m;
}

void ProGamerMove(){
	cin>>n>>m;
	dp[n]=pref[n]=1;
	for(int i=n-1;i>=1;--i){
		dp[i]=pref[i+1];
		for(int j=2;j*i<=n;++j)dp[i]=(dp[i]+query(j*i,j*i+j))%m;
//		cerr<<i<<" "<<dp[i]<<endl;
		pref[i]=(dp[i]+pref[i+1])%m;
	}
	cout<<(dp[1]+m)%m<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}