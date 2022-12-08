#include <stdio.h>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

ll qmul(ll a, ll b, ll m) { a %= m; b %= m;
ll r = a * b, s = ld(a) * b / m;
return ((r - m * s) % m + m) % m;
}
ll qpow ( ll f , ll x , ll mod ) {
	ll s = 1;
	while ( x ) {
		if ( x % 2 == 1 ) s = qmul ( s , f , mod );
		f = qmul ( f , f , mod ); x = x / 2;
	}
	return s % mod;
}
bool miller_rabin(ll n, ll base) {
ll n2 = n - 1, s = 0;
while(n2 % 2 == 0) n2 /= 2, s ++;
ll t = qpow(base, n2, n);
if(t == 1 || t == n - 1) return true;
for(s --; s >= 0; s --)
if((t = qmul(t, t, n)) == n - 1) return true;
return false;
}
bool is_prime(ll n) {
static ll base[] = {2,3,5,7,11,13,17,19,23,29,31,37};
if(n < 2) return false;
for(int i = 0; i < 12 && base[i] < n; i ++) {
if(!miller_rabin(n, base[i])) return false;
}
return true;
}
ll f(ll x, ll m) { return (qmul(x, x, m) + 1) % m; }
ll rho(ll n) {
if(is_prime(n)) return n;
if(n % 2 == 0) return 2;
for(int i = 1; ; i ++) {
ll x = i, y = f(x, n), p = __gcd(y - x, n);
while(p == 1) { x = f(x, n); y = f(f(y, n), n);
p = __gcd((y - x + n) % n, n) % n;
}
if(p != 0 && p != n) return p;
}
}
ll n;
map < ll , ll > ma;
map < ll , ll >::iterator it;
queue < int > q;
ll a[220000] , p[22222]={0,2,3,5,7,11,13,17,19,23,29};
ll ans , del;
ll getans ( ll x ) {
	ll i , ret;
	ret = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( a[i] <= x ) {
			ret += x - a[i];
		}
		else ret += min ( (a[i]%x) , x - (a[i]%x) );
		if ( x != 2 && ret > ans ) return ans + 1;
	}
	//printf ( "%lld %lld\n" , x , ret );
	return ret;
}
void factor ( ll t ) {
	ll i , j , x , xx;
	x = t;
	for ( i = 2 ; i * i <= t ; i++ ) {
		if ( x % i == 0 ) {
			if ( !ma[i] ) ans = min ( getans ( i ) , ans );
			ma[i] = 1;
			while ( x % i == 0 ) x = x / i;
		}
	}
	if ( x != 1 ) {
		if ( !ma[x] ) ans = min ( ans , getans ( x ) );
		ma[x] = 1;
	}
}
void work () {
	ll i , j , l , o , k , t , tt , p;
	scanf ( "%lld" , &n );
	//n = 200000;
	
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i] );
		/*do {
			a[i] = rand () * rand ();
		} while ( a[i] == 0 );*/
		
		
		//if ( i > 10000 ) printf ( "##%lld\n" , a[i] );
		/*t = a[i];
		for ( j = 1 ; j <= 10 ; j++ ) {
			if ( t % p[j] == 0 ) {
				ma[p[j]]++;
				while ( t % p[j] == 0 ) t = t / p[j];
			}
		}
		while ( t != 1 ) {
			tt = rho ( t );
			//printf ( "%lld %lld\n" , t , tt );
			while ( t % tt == 0 ) t /= tt;
			ma[tt]++;
		}*/
		if ( a[i] == 1 ) {
			a[i] = 2;
			del++;
		}
	}
	ans = getans ( 2 );
	srand(67890);
	for ( i = 1 ; i <= 50 ; i++ ) {
		j = rand () * rand () % n + 1;
		k = rand () * rand () % n + 1;
		for ( l = max ( 2ll , a[j] - 1 ) ; l <= a[j] + 1 ; l++ ) {
			for ( o = max ( 2ll , a[k] - 1 ) ; o <= a[k] + 1 ; o++ ) {
				t = __gcd ( l , o );
				if ( t != 1 ) {
					factor ( t );
					/*q.push ( t );
					while ( q.size () ) {
						tt = rho ( q.front () );
						p = q.front ();
						q.pop ();
						if ( tt == p ) {
							if ( !ma[tt] ) {
								ans = min ( ans , getans ( tt ) );
								//printf ( "%lld %lld\n" , tt , ans );
							}
							ma[tt] = 1;
						}
						else {
							if ( tt == 1 ) continue;
							q.push ( tt );
							q.push ( p / tt );
						}
					}*/
					/*if ( !ma[t] ) {
						ans = min ( ans , getans ( t ) );
					}
					ma[t] = 1;*/
				}
			}
		}
	}
	printf ( "%lld\n" , ans + del );
}
int main () {
	work ();
	return 0;
}