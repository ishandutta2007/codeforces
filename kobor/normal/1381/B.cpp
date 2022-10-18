// Krzysztof Boryczka
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

const int N=2020;

bitset<N> dp;
int n;

void solve(){
	dp.reset();
	dp[0]=1;
	int last=-1, rozm=0, a;
	vi items;
	cin>>n;
	FOR(i, 1, n*2){
		cin>>a;
		if(a<last) rozm++;
		else{
			last=a;
			items.pb(rozm);
			rozm=1;
		}
	}
	if(rozm) items.pb(rozm);
	for(auto &x: items) dp|=(dp<<x);
	cout<<(dp[n] ? "YES" : "NO")<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    FOR(te, 1, tt){
		// cout<<"Case #"<<te<<": ";
		solve();
	}
	// solve();
	return 0;
}