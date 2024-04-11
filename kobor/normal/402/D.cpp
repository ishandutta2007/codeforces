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

const int N=5050;

int n, m;
int prefgcd[N], prefval[N], dp[N], valgcd[N];
int t[N], bad[N];

bool isbad(int val){
	return *lower_bound(bad+1, bad+m+1, val)==val;
}

int licz(int val){
	if(val==1) return 0;
	for(int i=2; i*i<=val; i++) if(val%i==0) return licz(val/i)+1-2*isbad(i);
	return licz(val/val)+1-2*isbad(val);
}

void solve(){
	cin>>n>>m;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, m) cin>>bad[i];
	t[n+1]=1;
	prefgcd[0]=t[1];
	sort(bad+1, bad+m+1);
	FOR(i, 1, n+1) prefval[i]=prefval[i-1]+licz(t[i]);
	FOR(i, 1, n+1) prefgcd[i]=__gcd(prefgcd[i-1], t[i]);
	FOR(i, 1, n+1) valgcd[i]=licz(prefgcd[i]);
	memset(dp, -inf, sizeof(dp));
	dp[n+1]=0;
	FORD(i, n, 0) FOR(j, i+1, n+1) dp[i]=max(dp[i], dp[j]+prefval[j]-prefval[i]-valgcd[j]*(j-i));
	cout<<dp[0]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}