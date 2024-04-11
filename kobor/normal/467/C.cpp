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

ll dp[N][N];
int t[N];
ll pref[N], maksima[N];
ll ans;
int n, m, k;

ll sum(int l, int r){
	return pref[r]-pref[l-1];
}

void solve(){
	cin>>n>>m>>k;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, n) pref[i]=pref[i-1]+t[i];
	FOR(i, m, n){
		FOR(j, 0, k) maksima[j]=max(maksima[j], dp[i-m][j]);
		FOR(j, 1, k) dp[i][j]=sum(i-m+1, i)+maksima[j-1];
		ans=max(ans, dp[i][k]);
	}
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