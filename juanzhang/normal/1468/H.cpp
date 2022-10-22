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
int n , k , m;
int A[MAXN] , sp[MAXN] , ss[MAXN];
void solve() {
	cin >> n >> k >> m;
	rep( i , 1 , n ) A[i] = 0;
	int p , s = n;
	rep( i , 1 , m ) scanf("%d",&p) , A[p] = 1 , -- s;
	if( s % ( k - 1 ) ) { puts("NO"); return; }
	rep( i , 1 , n ) sp[i] = sp[i - 1] + ( A[i] == 0 );
	per( i , n , 1 ) ss[i] = ss[i + 1] + ( A[i] == 0 );
	rep( i , 1 , n ) if( A[i] ) {
		if( sp[i] >= k / 2 && ss[i] >= k / 2 ) {
			puts("YES");
			return;
		}
	}
	puts("NO");
}

signed main() {
//	freopen("ex_data3.in","r",stdin);
	int T;cin >> T;while( T-- ) solve();
//	solve();
}