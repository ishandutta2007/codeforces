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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

ll a[4], d[4];

ll tt, to, st, so;

int main(){

  REP( i , 4 ) scanf( "%lld %lld" , &a[i] , &d[i] );

  REP( swap_swapo , 2 ){
    tt = to = 0;
    REP( swap_swapt , 2 ){
      if( a[2] > d[1] && d[3] > a[0] ) tt++;
      if( a[2] < d[1] && d[3] < a[0] ) to++;
      swap( a[2] , a[3] );
      swap( d[2] , d[3] );
    }
    if( tt >= 1 ) st++;
    if( to == 2 ) so++;
    swap( a[0] , a[1] );
    swap( d[0] , d[1] );
  }

  if( so >= 1 ) printf( "Team 1\n" );
  else if( st == 2 ) printf( "Team 2\n" );
  else printf( "Draw\n" );
  
  return 0;
}