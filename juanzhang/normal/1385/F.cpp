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
#define MAXN 200006
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
int A[MAXN];
vi G[MAXN];
int f[MAXN] , deg[MAXN];
int tr[MAXN] , vis[MAXN];
void solve() {
	cin >> n >> k;
	rep( i , 1 , n ) G[i].clear() , deg[i] = 0;
	rep( i , 2 , n ) {
		static int u , v; scanf("%d%d",&u,&v);
		G[u].pb( v ) , G[v].pb( u ) , ++ deg[v] , ++ deg[u];
	}
	queue<int> Q;
	rep( i , 1 , n ) if( deg[i] == 1 ) Q.push( i ) , vis[i] = 1;
	rep( i , 1 , n ) tr[i] = 0;
	int as = 0;
	while( !Q.empty() ) {
		int u = Q.front(); Q.pop();
		deg[u] = 0;
		for( int v : G[u] ) if( deg[v] ) { 
			-- deg[v] , ++ tr[v];
			if( tr[v] % k == 0 ) ++ as;
			if( deg[v] == 1 && tr[v] % k == 0 ) Q.push( v ) , vis[v] = 1;
		}
	}
	cout << as << endl;
}

signed main() {
    int T;cin >> T;while( T-- ) solve();
//    solve();
}