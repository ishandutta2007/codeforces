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

const int N=3e5+5;

vector<pair<int, ii>> edg;
vi upd;
int dp[N], akt[N];
int n, m;

void solve(){
	int a, b, c;
	cin>>n>>m;
	FOR(i, 1, m){
		cin>>a>>b>>c;
		edg.pb({c, {a, b}});
	}
	edg.pb({inf, {0, 0}});
	sort(edg.begin(), edg.end());
	FOR(i, 0, SIZE(edg)-2){
		if(dp[edg[i].nd.st]+1>akt[edg[i].nd.nd]){
			akt[edg[i].nd.nd]=dp[edg[i].nd.st]+1;
			upd.pb(edg[i].nd.nd);
		}
		if(edg[i].st!=edg[i+1].st){
			for(auto &x: upd) dp[x]=akt[x];
			upd.clear();
		}
	}
	cout<<*max_element(dp+1, dp+n+1)<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}