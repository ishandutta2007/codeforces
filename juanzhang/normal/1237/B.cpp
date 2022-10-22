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

void solve() {
	cin >> n;
	rep( i , 1 , n ) scanf("%d",A + i) , bc[A[i]] = i;
	rep( i , 1 , n ) scanf("%d",B + i);
	int as = 0;
	per( i , n , 1 ) {
		int t = bc[B[i]];
		if( sum( t ) ) ++ as;
		add( t , 1 );
	}
	cout << as << endl;
}

signed main() {
//    int T;cin >> T;while( T-- ) solve();
    solve();
}