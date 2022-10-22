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
int A[MAXN];
char ch[MAXN];
set<int> p0 , p1;
vector<vector<int>> re;
void solve() {
	scanf("%s",ch + 1);
	n = strlen( ch + 1 );
	rep( i , 1 , n ) {
		A[i] = ch[i] - '0';
		if( A[i] == 0 ) p0.insert( i );
		else p1.insert( i );
	}
	while( p0.size() ) {
		vi ee;
		int t = *p0.begin();
		p0.erase( p0.begin() );
		ee.pb( t );
		while( p1.size() ) {
			auto t1 = p1.lower_bound( t );
			auto t0 = p0.lower_bound( *t1 );
			if( t1 == p1.end() || t0 == p0.end() ) break;
			t = *t0;
			ee.pb( *t1 ) , ee.pb( *t0 );
			p0.erase( t0 ) , p1.erase( t1 );
		}
		re.pb( ee );
	}
	if( p1.size() ) puts("-1") , exit(0);
	cout << re.size() << endl;
	for( auto& t : re ) {
		printf("%d ",t.size());
		for( auto& x : t ) printf("%d ",x);
		puts("");
	}
	
	
}

signed main() {
//    int T;cin >> T;while( T-- ) solve();
    solve();
}