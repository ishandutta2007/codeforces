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
#define int long long
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
int n , m;
int A[MAXN];

pii gmx( int l , int r ) {
	int S = 0 , s = 0;
	rep( i , l , r ) S += A[i];
	pii as = mp( -S , l - 1 );
	rep( i , l , r ) {
		s += A[i];
		as = max( as , mp( s * 2 - S , i ) );
	}
	return as;
}

void solve() {
	cin >> n;
	rep( i , 1 , n ) scanf("%lld",A + i);
	pii as = gmx( 1 , n );
	pii ps = mp( 0x3f3f3f3f , n );
	rep( k , 1 , n - 1 ) {
		pii l = gmx( 1 , k ) , r = gmx( k + 1 , n );
		if( l.fi + r.fi > as.fi ) {
			as = mp( l.fi + r.fi , k );
			ps = mp( l.se , r.se );
		}
	}
	if( ps.fi > 1e9 ) {
		cout << as.se << ' ' << n << ' ' << n << endl;
		return;
	}
	cout << ps.fi << ' ' << as.se << ' ' << ps.se << endl;
}	

signed main() {
//    int T;cin >> T;while( T-- ) solve();
    solve();
}