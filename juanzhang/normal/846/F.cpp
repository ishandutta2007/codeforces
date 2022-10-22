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
#define MAXN 2000006
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
int n;
int A[MAXN];
int pr[MAXN] , lst[MAXN];
void solve() {
	cin >> n;
	rep( i , 1 , n ) scanf("%d",A + i);
	ll sl = 0 , as = 0;
	rep( i , 1 , n ) {
		lst[i] = pr[A[i]];
		pr[A[i]] = i;
		sl += lst[i];
		as += ( i + 1 ) * 1ll * i / 2 - sl;
	}
	printf("%.6lf\n",1. * ( 2 * as - n ) / ( n * 1ll * n ));
}

signed main() {
//    int T;cin >> T;while( T-- ) solve();
    solve();
}