#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;

const int INF = 1e9;
const ll INFLL = 1e18;
const ld EPS = 1e-8;
const ld EPSLD = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1010;

int n, m;
int a[MAX_N][MAX_N];

int ans = 0;
int t, x;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) REP( j , n ) scanf( "%d" , &a[i][j] );
  REP( i , n ) ans ^= a[i][i];
  
  scanf( "%d" , &m );
  REP( i , m ){
    scanf( "%d" , &t );
    if( t == 1 || t == 2 ){
      scanf( "%d" , &x ); ans ^= 1;
    } else if( t == 3 ){
      printf( "%d" , ans );
    }
  }

  printf( "\n" );

  return 0;
}