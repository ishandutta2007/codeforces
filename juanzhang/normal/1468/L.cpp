#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include "cmath"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "cassert"
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

ll mul( ll a , ll b , ll p ) {
	return ( a * b - (ll) ( (long double) a / p * b + 0.5 ) * p + p ) % p;
}

ll Pow( ll x , ll a , ll p ) {
	ll ret = 1;
	while( a ) {
		if( a & 1 ) ret = mul( ret , x , p );
		x = mul( x , x , p ) , a >>= 1;
	}
	return ret;
}

const int _ps[] = { 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 } , _l = 9;
bool millerRabin( ll x ) {
	if( x == 1 ) return false;
	ll t = x - 1; int cnt = 0;
	while( ~t & 1 ) t >>= 1 , ++ cnt;
	rep( i , 0 , _l - 1 ) {
		if( x == _ps[i] ) return true;
		ll a = Pow( _ps[i] , t , x ) , nex;
		rep( j , 1 , cnt ) {
			nex = mul( a , a , x );
			if( nex == 1 && a != x - 1 && a != 1 ) return false;
			a = nex;
		}
		if( a != 1 ) return false;
	}
	return true;
}

int n , k;
ll A[MAXN];
map<ll,vector<ll> > M;

ll Pow( ll x , int a ) {
	ll ret = 1;
	while( a ) {
		if( a & 1 ) ret = ret * 1ll * x;
		a >>= 1 , x = x * 1ll * x;
	}
	return ret;
}

int pr[MAXN];

vector<vector<ll>> V;
set<ll> ok;
multiset<ll> o2;

void solve() {
	cin >> n >> k;
	rep( i , 1 , n ) scanf("%lld",A + i);
	if( k == 1 ) { puts("0"); return; }
	rep( i , 1 , n ) {
		rep( k , 2 , 10 ) {
			int t = pow( A[i] , 1. / k );
			rep( j , max( t - 10 , 1ll ) , t + 10 ) {
				if( Pow( j , k ) == A[i] ) {
					pr[i] = j;
					break;
				}
			}
			if( pr[i] ) break;
		}
		if( pr[i] ) {
			for( int j = 2 ; j * j <= pr[i] ; ++ j ) if( pr[i] % j == 0 ) {
				while( pr[i] % j == 0 ) pr[i] /= j;
				if( pr[i] == 1 ) pr[i] = j;
				else pr[i] = -1;
				break;
			}
		}
	}
	rep( i , 1 , n ) if( !pr[i] ) {
		if( millerRabin( A[i] ) ) {
			M[A[i]].pb( A[i] );
			pr[i] = -1;
			continue;
		}
		ll x = A[i];
		rep( k , 2 , 100 ) if( x % k == 0 ) {
			while( x % k == 0 ) x /= k;
			if( x == 1 ) pr[i] = k;
			else pr[i] = -1;
			break;
		}
		if( !pr[i] ) pr[i] = -1;
	}
	rep( i , 1 , n ) if( ~pr[i] ) {
		M[pr[i]].pb( A[i] );
	}
	
	vector<ll> ps;
	for( auto t : M ) {
		if( t.se.size() >= 2 ) {
			V.pb( t.se ) , ps.pb( t.fi );
			o2.insert( t.se.back() );
			o2.insert( *( t.se.rbegin() + 1 ) );
		}
	}
	
	int od = k & 1;
	vector<ll> as;
	int mx = 0 , tr = 0;
	multiset<ll> ur;
	for( auto& t : V ) if( t.size() >= 2 ) {
		if( tr + 2 <= k ) {
			as.pb( t.back() );
			as.pb( *( t.rbegin() + 1 ) );
			tr += 2;
		}
		if( tr >= k ) break;
	}
	if( tr == k ) {
		for( auto x : as ) printf("%lld ",x);
		return;
	}
	for( ll x : as ) ur.insert( x );
	if( tr == k - 1 ) {
		as.clear();
		rep( i , 1 , n ) {
			ll fk = A[i];
			if( o2.count( A[i] ) ) {
				o2.erase( o2.find( A[i] ) );
				continue;
			}
			ok.clear() , as.clear();
			for( auto& t : M ) if( t.se.size() >= 2 && fk % t.fi == 0 ) {
				while( fk % t.fi == 0 ) fk /= t.fi;
				as.pb( t.se.back() );
				as.pb( *( t.se.rbegin() + 1 ) );
				ok.insert( t.fi );
				if( fk == 1 ) break;
			}
			if( as.size() > k ) continue;
			if( fk == 1 ) {
				as.pb( A[i] );
				for( auto& t : M ) {
					if( as.size() == k ) break;
					if( t.se.size() >= 2 && !ok.count( t.fi ) ) {
						as.pb( t.se.back() );
						as.pb( *( t.se.rbegin() + 1 ) );
					}
				}
				if( as.size() == k ) {
					for( ll x : as ) printf("%lld ",x);
					return;
				} else assert( 0 );
			}
		}
		puts("0");
		return;
	}
	assert( tr < k );
	rep( i , 1 , n ) {
		ll t = A[i];
		for( int x : ps ) {
			while( t % x == 0 ) t /= x;
			if( t == 1 ) break;
		}
		if( t == 1 ) {
			if( ur.count( A[i] ) ) ur.erase( ur.find( A[i] ) );
			else as.pb( A[i] );
			if( as.size() >= k ) break;
		}
	}
	if( as.size() < k ) puts("0");
	else for( ll x : as ) printf("%lld ",x);
}

signed main() {
//	int T;cin >> T;while( T-- ) solve();
	solve();
}