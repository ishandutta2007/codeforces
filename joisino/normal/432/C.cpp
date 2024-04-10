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

class Primes : public vi{
public:
  vb isp;
  Primes( int max_n ){
    isp = vb( max_n , true );
    FOR( i , 2 , max_n ){
      if( isp[i] ){
	pb( i );
	for( int j = i*2; j < max_n; j += i ) isp[j] = false;
      }
    }
  }
};

const int MAX_N = 100010;

Primes ps( MAX_N );

int n;
int a[MAX_N];

int pa[MAX_N];

int pos[MAX_N];

vpi ans;

void sw( int x , int y ){
  ans.pb( min( x , y ) , max( x , y ) );
  swap( pos[ a[x] ] , pos[ a[y] ] );
  swap( a[x] , a[y] );
}

int main(){
  
  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );

  for( int i = 10; i < MAX_N; i += 2 ){
    YYS( w , ps ) if( ps.isp[ i-w ] ){
      pa[i] = w;
      break;
    }
  }

  REP( i , n ) pos[ a[i] ] = i;

  FOR( i , 1 , n+1 ){
    int sa = pos[i] - i + 2;
    if( sa % 2 == 0 ){
      sa--;
      sw( pos[i] , pos[i]-1 );
    }
    if( sa == 1 ) continue;
    if( ps.isp[sa] ){
      sw( pos[i] , i-1 );
    } else {
      int p1 = pa[sa+1];
      int p2 = sa+1 - p1;
      sw( pos[i] , pos[i] - p1 + 1 );
      sw( pos[i] , pos[i] - p2 + 1 );
    }
  }

  printf( "%d\n" , (int)ans.size() );
  YYS( w , ans ) printf( "%d %d\n" , w.fi+1 , w.se+1 );
  
  return 0;
}