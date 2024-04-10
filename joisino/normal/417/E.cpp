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

const int MAX_N = 128;

void yuyu( int n , int *a ){
  if( n == 1 ){
    a[0] = 1;
  } else if( n == 2 ){
    a[0] = 3;
    a[1] = 4;
  } else if( n % 2 == 0 ){
    REP( i , n-1 ) a[i] = 1;
    a[n-1] = n / 2 - 1;
  } else if( n % 2 == 1 ){
    REP( i , n-2 ) a[i] = 1;
    a[n-2] = 2;
    a[n-1] = ( n + 1 ) / 2;
  }
}

int n, m;

int a[MAX_N], b[MAX_N];

int main(){

  scanf( "%d %d" , &n , &m );

  yuyu( n , a );
  yuyu( m , b );

  REP( i , n ) REP( j , m ) printf( "%d%c" , a[i] * b[j] , j == m-1 ? '\n':' ' );
  
  return 0;
}