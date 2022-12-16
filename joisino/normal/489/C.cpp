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

int minans[MAX_N], maxans[MAX_N];;

int m, s;

int main(){

  scanf( "%d %d" , &m , &s );

  if( s == 0 && m == 1 ){
    printf( "0 0\n" );
    return 0;
  }
  
  if( s == 0 || s > 9*m ){
    printf( "-1 -1\n" );
    return 0;
  }

  minans[0] = 1;
  int p = m-1;
  REP( i , s-1 ){
    if( minans[p] == 9 ) p--;
    minans[p]++;
  }

  p = 0;
  REP( i , s ){
    if( maxans[p] == 9 ) p++;
    maxans[p]++;
  }

  REP( i , m ) printf( "%d" , minans[i] );
  printf( " " );
  REP( i , m ) printf( "%d" , maxans[i] );
  printf( "\n" );
  
  
  return 0;
}