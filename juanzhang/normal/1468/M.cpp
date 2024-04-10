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
#define MAXN 500006
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
#define P 1000000007
int n , m;
int A[MAXN];
vi G[MAXN] , g[MAXN];
int nm[MAXN];
vector<int> nd;
int deg[MAXN];
void pt( int x ) {
	if( x <= n ) printf("%d ",x);
}
void solve() {
	cin >> n;
	nd.clear();
	rep( i , 1 , n ) {
		int k , v;
		scanf("%d",&k);
		rep( j , 1 , k ) {
			scanf("%d",&v);
			nd.pb( v );
			G[i].pb( v );
		}
	}
	sort( all( nd ) );
	nd.erase( unique( all( nd ) ) , nd.end() );
	rep( i , 1 , n ) for( int& x : G[i] ) {
			x = lower_bound( all( nd ) , x ) - nd.begin() + 1 + n;
			G[x].pb( i );
			++ deg[x] , ++ deg[i];
		}
//	rep( i , 1 , n ) {
//		for( int x : G[i] ) printf("%d ",x);
//		puts("");
//	}
	int flg = 0;
	rep( i , 1 , n + nd.size() ) for( int v : G[i] ) if( deg[v] > deg[i] || ( deg[v] == deg[i] && v > i ) ) {
		g[i].pb( v );
//		cout << i << ' ' << v << endl;
	}
	rep( i , 1 , n + nd.size() ) {
		if( deg[i] >= 2 ) {
			for( int v : G[i] ) if( deg[v] >= 2 ) {
				for( int t : g[v] ) {
					if( nm[t] && t != i ) {
						pt( i ) , pt( t ) , pt( nm[t] ) , pt( v );
						puts("");
						flg = 1;
						break;
					}
					nm[t] = v;
				}
				if( flg ) break;
			}
			if( flg ) break;
			for( int v : G[i] ) if( deg[v] >= 2 )
				for( int t : g[v] ) nm[t] = 0;
		}
	}
	if( !flg ) puts("-1");
	rep( i , 1 , n + nd.size() ) G[i].clear() , g[i].clear() , deg[i] = nm[i] = 0;
}

signed main() {
//	freopen("ex_data3.in","r",stdin);
	int T;cin >> T;while( T-- ) solve();
//	solve();
}