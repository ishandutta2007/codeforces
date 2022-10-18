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

int n, r, ans, lans;
vii spoko, nie;
int dp[60010];

bool cmp(const ii &a, const ii &b){
	return a.st+a.nd>b.st+b.nd;
}

void solve(){
	int a, b;
	cin>>n>>r;
	FOR(i, 1, n){
		cin>>a>>b;
		a=max(a, -b);
		if(b>=0) spoko.pb({a, b});
		else nie.pb({a, b});
	}
	sort(spoko.begin(), spoko.end());
	sort(nie.begin(), nie.end(), cmp);
	for(auto &x: spoko) if(r>=x.st) r+=x.nd, ans++;
	memset(dp, -inf, sizeof(dp));
	dp[r]=0;
	for(auto &x: nie) FOR(j, x.st, r) dp[j+x.nd]=max(dp[j+x.nd], dp[j]+1);
	cout<<ans+*max_element(dp, dp+sizeof(dp)/sizeof(int))<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}