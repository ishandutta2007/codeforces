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

const int MAX_N = 100010;

int n;
ll pr = -1;

char s[MAX_N][10];
int d[MAX_N];

ll base[18];

bool dfs( int id , int p , ll cur ){
  if( p == d[id] ) return cur > pr;

  ll cd = d[id] - 1 - p;
  if( s[id][p] != '?' ) return dfs( id , p+1 , cur + base[cd] * ( s[id][p] - '0' ) );
  
  REP( i , 10 ){
    if( p == 0 && i == 0 ) continue;
    if( cur + base[cd] * i > pr && dfs( id , p+1 , cur + base[cd] * i ) ){
      s[id][p] = '0' + i;
      return true;
    }
    if( cur + base[cd] * i <= pr && cur + base[cd] * ( i + 1 ) > pr && dfs( id , p+1 , cur + base[cd] * i ) ){
      s[id][p] = '0' + i;
      return true;
    }
  }
  return false;
}

int main(){

  base[0] = 1;
  FOR( i , 1 , 18 ) base[i] = base[i-1] * 10;

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%s" , s[i] );
  REP( i , n ) d[i] = strlen( s[i] );

  REP( i , n ){
    if( !dfs( i , 0 , 0 ) || s[i][0] == '0' ) return puts( "NO" );
    pr = 0;
    REP( j , d[i] ) pr = pr * 10 + ( s[i][j] - '0' );
  }

  printf( "YES\n" );
  REP( i , n ) printf( "%s\n" , s[i] );
  
  
  return 0;
}