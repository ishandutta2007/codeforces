//Krzysztof Boryczka
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

const int RNG=250, N=3e4;

int n, d, a, ans, offset;
int gem[N+5], dp[N+5][2*RNG+5];

void solve(){
	cin>>n>>d;
	offset=d-RNG;
	FOR(i, 1, n){
		cin>>a;
		gem[a]++;
	}
	memset(dp, -128, sizeof(dp));
	ans=dp[d][d-offset]=gem[d];
	FOR(i, d+1, N){
		FOR(k, max(1, d-RNG), d+RNG){
			if(i<k) break;
			// cout<<k<<sp<<offset<<ent;
			dp[i][k-offset]=max({dp[i-k][k-1-offset], dp[i-k][k-offset], dp[i-k][k+1-offset]})+gem[i];
			ans=max(ans, dp[i][k-offset]);
		}
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}