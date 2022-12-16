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

double da, dd;
ll n;

ll cur;

int cnt = 1;
void answer( ll a , ll b ){
  printf( "%.18lf %.18lf\n" , (double)a/10000.0 , (double)b/10000.0 );
}

int main(){

  scanf( "%lf%lf" , &da , &dd );
  scanf( "%lld" , &n );
  ll a = (da+EPS) * 10000, d = (dd+EPS) * 10000;

  REP( i , n ){
    cur += d;
    cur -= cur / (4*a) * 4*a;
    ll p = cur / a;
    if( p == 0 ) answer( cur , 0 );
    else if( p == 1 ) answer( a , cur-a );
    else if( p == 2 ) answer( 3*a-cur , a );
    else if( p == 3 ) answer( 0 , 4*a-cur );
  }
  
  
  return 0;
}