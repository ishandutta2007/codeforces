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

const string po[] = { "popStack" , "popQueue" , "popFront" };
const string pu[] = { "pushStack" , "pushQueue" , "pushFront" , "pushBack" };

ll n, a;
vl res;
vpl v;

int main(){

  scanf( "%lld" , &n );
  REP( ind , n ){
    scanf( "%lld" , &a );
    if( a == 0 ){
      SORT( v );
      REVERSE( v );

      REP( i , min( 3LL , SZ(v) ) ) res.pb( v[i].se - ( ind - SZ(v) ) );
      SORT( res );

      ll p = 0;
      REP( i , SZ(v) ){
	if( p < SZ(res) && i == res[p] ){
	  printf( "%s\n" , pu[p++].c_str() );
	} else {
	  printf( "%s\n" , pu[3].c_str() );
	}
      }

      printf( "%lld" , p );
      REP( i , p ) printf( " %s" , po[i].c_str() );
      printf( "\n" );
      
      v.clear();
      res.clear();
    } else {
      v.pb( a , ind );
    }
  }

  REP( i , SZ(v) ) printf( "%s\n" , pu[3].c_str() );
  
  return 0;
}