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

const int N=62;

int dist[N][N][N], ans[N][N][N];
int n, m, r, s, t, kk;

void solve(){
	cin>>n>>m>>r;
	memset(ans, inf, sizeof(ans));
	FOR(l, 1, m) FOR(i, 1, n) FOR(j, 1, n) cin>>dist[l][i][j];
	FOR(l, 1, m) FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) dist[l][i][j]=min(dist[l][i][j], dist[l][i][k]+dist[l][k][j]);
	FOR(l, 1, m) FOR(i, 1, n) FOR(j, 1, n) ans[0][i][j]=min(ans[0][i][j], dist[l][i][j]);
	FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) FOR(l, 1, n) ans[k][i][j]=min(ans[k][i][j], ans[k-1][i][l]+ans[0][l][j]);
	FOR(i, 1, r) cin>>s>>t>>kk, cout<<ans[min(n, kk)][s][t]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}