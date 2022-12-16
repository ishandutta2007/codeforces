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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


const int MAX_N = 128;

int n;
char field[MAX_N][MAX_N];

vpi ans;

bool getans(){
  ans.clear();
  REP( i , n ){
    bool ok = false;
    REP( j , n ){
      if( field[i][j] == '.' ){
	ans.pb( i+1 , j+1 );
	ok = true;
	break;
      }
    }
    if( !ok ) return false;
  }
  return true;
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%s" , field[i] );

  REP( i , 2 ){
    if( getans() ){
      YYS( w , ans ){
	if( i == 1 ) swap( w.fi , w.se );
	printf( "%d %d\n" , w.fi , w.se );
      }
      return 0;
    }
    REP( i , n ) REP( j , i ) swap( field[i][j] , field[j][i] );
  }

  puts( "-1" );
  
  return 0;
}