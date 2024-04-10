#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include "cmath"
#include "vector"
#include "map"
#include "set"
#include "queue"
using namespace std;
#define MAXN 206
//#define int long long
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x) (x).begin() , (x).end()
#define mem( a ) memset( a , 0 , sizeof a )
typedef long long ll;
int n , k;

int dp[MAXN][MAXN][MAXN][2];
vi G[MAXN];

int siz[MAXN];

void dfs( int u ) {
	int sz = 1;
	rep( i , 0 , G[u].size() ) memset( dp[u][i] , 0x3f , sizeof dp[u][i] );
	dp[u][G[u].size()][1][0] = dp[u][G[u].size()][1][1] = 0;
	per( t , G[u].size() - 1 , 0 ){
		int v = G[u][t];
		dfs( v );
		memcpy( dp[u][t] , dp[u][t + 1] , sizeof dp[u][t] );
		rep( i , 1 , siz[v] ) rep( j , 1 , sz ) {
			dp[u][t][i + j][1] = min( dp[u][t][i + j][1] , dp[u][t+1][j][0] + dp[v][0][i][1] + 1 );
			dp[u][t][i + j][1] = min( dp[u][t][i + j][1] , dp[u][t+1][j][1] + dp[v][0][i][0] + 2 );
			dp[u][t][i + j][0] = min( dp[u][t][i + j][0] , dp[u][t+1][j][0] + dp[v][0][i][0] + 2 );
		}
		sz += siz[v];
	}
	siz[u] = sz;
}
void wkr( int u , int k , int w ) {
	printf("%d ",u);
	int pr = -1 , ps = 0;
	if( w ) pr = 0;
	rep( t , 0 , G[u].size() - 1 ) {
		int v = G[u][t];
		int pd = dp[u][t][k][w];
		rep( i , 1 , min( k , siz[v] ) ) {
			int j = k - i;
			if( w && pd == dp[u][t+1][j][0] + dp[v][0][i][1] + 1 ) {
				pr = v , ps = i , w = 0 , k = j;
				break;
			}
			if( w && pd == dp[u][t+1][j][1] + dp[v][0][i][0] + 2 ) {
				wkr( v , i , 0 );
				printf("%d ",u);
				k = j;
				break;
			} else if( !w && pd == dp[u][t+1][j][0] + dp[v][0][i][0] + 2 ) {
				wkr( v , i , 0 );
				printf("%d ",u);
				k = j;
				break;
			}
		}
	}
	if( pr > 0 ) {
		wkr( pr , ps , 1 );
	}
}

void solve() {
	cin >> n >> k;
	rep( i , 1 , n ) G[i].clear();
	rep( i , 2 , n ) {
		int u;
		scanf("%d",&u);
		G[u].pb( i );
	}
	dfs( 1 );
	cout << dp[1][0][k][1] << endl;
	wkr( 1 , k , 1 );
	puts("");
}

signed main() {
   int T;cin >> T;while( T-- ) solve();
//    solve();
}