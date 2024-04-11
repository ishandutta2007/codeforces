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

const int N=100*100;

int n, k, ans=-1;
int tast[105], cal[105];
bitset<N+105> dp[N+5];

void solve(){
	cin>>n>>k;
	FOR(i, 1, n) cin>>tast[i];
	FOR(i, 1, n) cin>>cal[i];
	dp[0][0]=1;
	FOR(xd, 1, n){
		FORD(i, N, cal[xd]) dp[i]|=(dp[i-cal[xd]]<<tast[xd]);
	}
	FOR(i, 1, N/k) if(dp[i][i*k]) ans=i*k;
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