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

vl factor( ll x ){
  vl res;
  for( ll i = 1; i*i <= x; i++ ){
    if( x % i == 0 ){
      res.pb( i );
      if( i != x/i ) res.pb( x/i );
    }
  }
  return res;
}

const int MAX_N = 100010;

int n;
int last[MAX_N];

int main(){

  REP( i , MAX_N ) last[i] = -1;
  
  scanf( "%d" , &n );
  REP( i , n ){
    int x, y;
    scanf( "%d %d" , &x , &y );
    vl v = factor( x );
    int ans = 0;
    YYS( w , v ){
      if( last[w] < i-y ) ans++;
      last[w] = i;
    }
    printf( "%d\n" , ans );
  }
  
  return 0;
}