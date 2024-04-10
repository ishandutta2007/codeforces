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
#define MAXN 600006
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
int n , m;
int A[MAXN] , B[MAXN] , bc[MAXN];

int T[MAXN];
void add( int x , int c ) {
	while( x <= n ) T[x] += c , x += ( x & -x );
}
int sum( int x ) {
	int re = 0;
	while( x > 0 ) re += T[x] , x -= ( x & -x );
	return re;
}

int stk[MAXN] , top;
int nx[MAXN] , ps[MAXN] , as[MAXN];
int P[MAXN][22] , lg[MAXN];

inline int que( int l , int r ) {
    int L = lg[r - l + 1];
    return max( P[l][L] , P[r - ( 1 << L ) + 1][L] );
}

void solve() {
	cin >> n;
	rep( i , 1 , n ) scanf("%d",A + i) , A[i + n] = A[i + 2 * n] = A[i];
	n = n * 3;
	per( i , n , 1 ) {
		pii smn = mp( A[i] , i );
		while( top && A[i] > A[stk[top]] ) {
			-- top;
		}
		nx[i] = stk[top];
		stk[++ top] = i;
	}
	stk[0] = 0x3f3f3f3f;
	while( top ) {
		nx[stk[top]] = stk[top - 1];
		-- top;
	}
	lg[0] = -1;
    for( int i = 1 ; i <= n ; ++ i ) lg[i] = lg[i - 1] + ( (i & -i) == i ) , P[i][0] = A[i];
    for( int i = 1 ; i < 21 ; ++ i )
        for( int j = 1 ; j <= n - ( 1 << i ) + 1 ; ++ j )
            P[j][i] = min( P[j][i - 1] , P[j + ( 1 << i - 1 )][i - 1] );
    rep( i , 1 , n ) {
    	int st = i;
    	per( k , 20 , 0 ) {
    		int r = i + ( 1 << k ) - 1;
    		if( r > n ) continue;
    		if( P[i][k] > ( A[st] - 1 ) / 2 ) i = i + ( 1 << k );
		}
		ps[st] = i;
		if( ps[st] > n ) ps[st] = 0x3f3f3f3f;
		i = st;
	}
	per( i , n , 1 ) {
		if( ps[i] > nx[i] ) as[i] = as[nx[i]];
		else as[i] = ps[i];
	}
	rep( i , 1 , n / 3 ) printf("%d ",( as[i] > 1e9 ? -1 : as[i] - i ));
}

signed main() {
//    int T;cin >> T;while( T-- ) solve();
    solve();
}