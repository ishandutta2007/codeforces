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

const int N=1e5+5;

int n, m;
ii ant[85];
int dp[85][N];

void solve(){
	int a, b;
	memset(dp, inf, sizeof(dp));
	cin>>n>>m;
	FOR(i, 1, n){
		cin>>a>>b;
		ant[i]={max(a-b, 1), min(a+b, m)};
	}
	FOR(i, 1, n) FOR(j, 1, n){
		if(i==j) continue;
		if(ant[i].st == ant[j].st && ant[j].nd == ant[i].nd){
			ant[max(i, j)]={inf, inf};
			continue;
		}
		if(ant[i].st<=ant[j].st && ant[j].nd<=ant[i].nd) ant[j]={inf, inf};
	}
	sort(ant+1, ant+n+1);
	FOR(i, 1, n){
		if(ant[i].st==inf){
			n=i-1;
			break;
		}
	}
	FOR(i, 0, n) dp[i][0]=0;
	FOR(i, 1, n){
		FORD(j, m, 1){
			dp[i][j]=max({j-ant[i].nd, ant[i].st-1, 0});
			dp[i][j]=min({dp[i][j], dp[i][j+1], dp[i-1][j]});
			int roz=max(0, j-ant[i].nd);
			dp[i][j]=min(dp[i][j], roz+dp[i-1][max(0, ant[i].st-1-roz)]);
		}
	}
	cout<<dp[n][m]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}