#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define pb emplace_back
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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 200010;

int n;
ll a[MAX_N];

int ans = 0;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );

  ll d = INFLL;
  int p = -1;
  int skipped = INF;
  REP( i , n ){
    if( a[i] == -1 ){
      if( d != INFLL ){
	if( a[i-1] + d > 0 ) a[i] = a[i-1] + d;
	else d = INFLL, p = -1, skipped = i;
      } else {
	chmin( skipped , i );
      }
    } else {
      if( d != INFLL ){
	if( a[i] != a[i-1] + d ){
	  p = i;
	  d = INFLL;
	}
      } else if( d == INFLL && p >= 0 ){
	if( ( a[i] - a[p] ) % ( i - p ) == 0 ){
	  d = ( a[i] - a[p] ) / ( i - p );	  
	  if( skipped == INF || d * ( skipped - p ) + a[p] > 0 ){
	    FOR( j , skipped , i ) a[j] = d * ( j - p ) + a[p];
	  } else {
	    FOR( j , skipped , i ) a[j] = a[p];
	    p = i;
	    d = INFLL;
	  }
	} else {
	  FOR( j , skipped , i ) a[j] = a[p];
	  p = i;
	}
	skipped = INF;
      } else if( d == INFLL && p == -1 ){
	p = i;
      }
    }
  }

  if( d == INFLL && p >= 0 && skipped != INF ){
    FOR( j , skipped , n ) a[j] = a[p];
  }

  /*
  REP( i , n ) printf( "%lld " , a[i] );
  printf( "\n" );
  */

  d = INFLL;
  FOR( i , 1 , n ){
    if( d != INFLL ){
      if( a[i] != a[i-1] + d ){
	d = INFLL;
	ans++;
      }
    } else {
      d = a[i] - a[i-1];
    }
  }
  
  printf( "%d\n" , ans + 1 );
  
  return 0;
}