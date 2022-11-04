#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N=5005,mod=998244353;
int a[N];
int dp[N][N],add[N][N];
int pref[N];
int nxt[N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	int cur=0;
	for(int i=1;i<n;++i){
		while(a[cur]*2<=a[i])++cur;
		pref[i]=cur;
	}
	cur=n;
	for(int i=n-1;i>=0;--i){
		while(a[i]*2<=a[cur-1])--cur;
		nxt[i]=cur;
	}
	for(int i=0;i<n;++i)dp[i][0]=1;
	for(int j=0;j<n;++j) // done
		for(int i=0;i<n;++i){ // cur
			add[i+1][j]=(add[i+1][j]+add[i][j])%mod;
			dp[i][j]=(dp[i][j]+add[i][j])%mod;
			if(j<pref[i])dp[i][j+1]=(dp[i][j+1]+ll(pref[i]-j)*dp[i][j])%mod;
			add[nxt[i]][j+1]=(add[nxt[i]][j+1]+dp[i][j])%mod;
		}
	cout<<dp[n-1][n-1]<<endl;
}