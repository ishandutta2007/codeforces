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

int n, t;
char a[MAX_N], b[MAX_N], c[MAX_N];;

int dif, sam;

int both, onlya, onlyb;

char dc( char x , char y ){
  REP( i , 26 ) if( x != 'a'+i && y != 'a'+i ) return 'a'+i;
}

int main(){

  scanf( "%d %d" , &n , &t );
  scanf( "%s %s" , a , b );

  REP( i , n ) if( a[i] != b[i] ) dif++;
  int mdif = dif / 2 + dif % 2;

  if( mdif > t ){
    printf( "-1\n" );
    return 0;
  }

    REP( i , n-dif+1 ){
    int x = i + dif - t;
    if( 0 <= x && x <= dif/2 ){
      both = n - dif - i;
      onlya = onlyb = x;
      break;
    }
  }
  
  int cnt = dif;
  t -= mdif;
  REP( i , n ){
    if( a[i] == b[i] && both > 0 ) c[i] = a[i], both--;
    else if( a[i] != b[i] && onlya > 0 ) c[i] = a[i], onlya--;
    else if( a[i] != b[i] && onlyb > 0 ) c[i] = b[i], onlyb--;
    else c[i] = dc( a[i] , b[i] );
  }

  REP( i , n ) printf( "%c" , c[i] );
  printf( "\n" );
  
  return 0;
}