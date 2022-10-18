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

const int N=5050;
const int mod=1e9+7;

int dp[N][N];
string s, t;

void solve(){
	cin>>s>>t;
	FORD(i, SIZE(s)-1, 0){
		FORD(j, SIZE(t)-1, 0){
			dp[i][j]=dp[i][j+1];
			if(s[i]==t[j]) dp[i][j]=(dp[i][j]+dp[i+1][j+1]+1)%mod;
		}
	}
	int ans=0;
	FOR(i, 0, SIZE(s)-1) ans=(ans+dp[i][0])%mod;
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}