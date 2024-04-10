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

int n, m;
int a[MAX_N], b[MAX_N];

int ans;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );
  scanf( "%d" , &m );
  REP( i , m ) scanf( "%d" , &b[i] );

  sort( a , a+n );
  sort( b , b+m );

  int p = 0;
  REP( i , n ){
    while( p < m && b[p] < a[i]-1 ) p++;
    if( p == m ) break;
    if( a[i]-1 <= b[p] && b[p] <= a[i]+1 ){
      p++;
      ans++;
    }
  }

  printf( "%d\n" , ans );
  
  return 0;
}