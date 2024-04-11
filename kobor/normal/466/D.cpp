//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int N=2010;
const int mod=1e9+7;

int t[N], dp[N][N], offset[N];
int n, h, a;

void solve(){
	cin>>n>>h;
	FOR(i, 1, n){
		cin>>a;
		t[i]=h-a;
	}
	dp[0][0]=1;
	FOR(i, 1, n){
		dp[i][t[i]]=dp[i-1][t[i]];
		if(t[i]>0) dp[i][t[i]]+=dp[i-1][t[i]-1];
		dp[i][t[i]]%=mod;

		if(t[i]==0) continue;
		dp[i][t[i]-1]=((ll)dp[i-1][t[i]]*t[i]+dp[i-1][t[i]-1])%mod;
		if(t[i]>0) dp[i][t[i]-1]+=(ll)dp[i-1][t[i]-1]*(t[i]-1)%mod;
		dp[i][t[i]-1]%=mod;


	}
	cout<<dp[n][0]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}