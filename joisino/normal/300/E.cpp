#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())

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
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

// head

const int MAX_N = 10000010;

int n;
int p[MAX_N];
int a[MAX_N];
ll c[MAX_N];

ll sum;

int nc[MAX_N];
bool check( ll x ){
  FOR( i , 2 , MAX_N ) if( p[i] == i ){
    ll s = 1;
    ll res = 0;
    while( s <= x / i ){
      s *= i;
      res += x / s;
    }
    if( res < c[i] ) return false;
  }
  return true;
}

int main(){

  REP( i , MAX_N ) p[i] = i;
  FOR( i , 2 , MAX_N ){
    if( p[i] == i ){
      for( int j = i; j < MAX_N; j += i ) chmin( p[j] , (int)i );
    }
  }

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );

  REP( i , n ) sum += a[i];
  
  REP( i , n ) c[1]++, c[a[i]+1]--;
  REP( i , MAX_N-1 ) c[i+1] += c[i];

  for( int i = MAX_N-1; i >= 2; i-- ){
    if( p[i] != i ) c[p[i]] += c[i];
    c[i/p[i]] += c[i];
  }

  ll lb = 0, ub = sum+1;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( check( md ) ) ub = md;
    else lb = md;
  }
  
  printf( "%lld\n" , ub );
  
  return 0;
}