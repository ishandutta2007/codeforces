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

const int MAX_N = 128;

int n, k, q;

bool used[MAX_N];

int a[MAX_N];
vi v;

int minv = INF;
int maxv = 0;

int main(){

  scanf( "%d %d" , &n , &k );
  REP( i , n ) scanf( "%d" , &a[i] );

  int theorem_per_card = n / k;

  scanf( "%d" , &q );
  REP( i , q ){
    int total = 0;
    REP( j , theorem_per_card ){
      int x;
      scanf( "%d" , &x ); x--;
      total += a[x];
      used[x] = true;
    }
    chmax( maxv , total );
    chmin( minv , total );
  }
  
  REP( i , n ) if( !used[i] ) v.pb( a[i] );

  if( ( n - (int)v.size() ) / theorem_per_card < k ){
    SORT( v );
    int total = 0;
    REP( i , theorem_per_card ) total += v[i];
    chmin( minv , total );
    
    REVERSE( v );
    total = 0;
    REP( i , theorem_per_card ) total += v[i];
    chmax( maxv , total );
  }


  
  printf( "%.18lf %.18lf\n" , (double)minv / (double)theorem_per_card , (double)maxv / (double)theorem_per_card );
  
  return 0;
}