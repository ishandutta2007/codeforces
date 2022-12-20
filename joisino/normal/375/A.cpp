#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
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

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1000010;

char cs[MAX_N];
string s;
bool used[10];
vi v, nv;
int x[4] = { 1 , 6 , 8 , 9  };

int calc(){
  int res = 0;
  YYS( w , nv ) res = ( res + w ) % 7 * 10;
  return res;
}

int main(){

  scanf( "%s" , cs ); s = cs;

  YYS( w , s ){
    int r = w - '0';
    if( ( r == 1 || r == 6 || r == 8 || r == 9 ) && !used[r] ) used[r] = true;
    else v.pb( r );
  }

  do{
    nv = v;
    REP( i , 4 ) nv.pb( x[i] );
    reverse( ALL(nv) );
    if( calc() == 0 ) break;
  } while( next_permutation( x , x+4 ) );

  YYS( w , nv ) printf( "%d" , w );
  printf( "\n" );
  
  return 0;
}