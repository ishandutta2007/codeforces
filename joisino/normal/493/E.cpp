#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

ll t, a, b;

int main(){

  scanf( "%lld %lld %lld" , &t , &a , &b );
  if( t == 1 ){
    if( a == 1 ){
      if( b == 1 ) puts( "inf" );
      else puts( "0" );
    } else {
      ll x = 1;
      ll res = 0;
      ll nb = b;
      while( b > 0 ){
	res += (b%a);
	b /= a;
      }
      if( res == a || ( res == 1 && nb >= a ) ) puts( "1" );
      else puts( "0" );
    }
  } else {
    if( t == a && a == b ) puts( "2" );
    else if( a == b ) puts( "1" );
    else if( a <= t ) puts( "0" );
    else{
      ll x = 1;
      ll res = 0;
      while( b > 0 ){
	res += (b%a)*x;
	b /= a;
	x *= t;
      }
      if( res == a ) puts( "1" );
      else puts( "0" );
    }
  }
  
  
  return 0;
}