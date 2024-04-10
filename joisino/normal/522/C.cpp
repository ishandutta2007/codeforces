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
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int test_case;

int m, k;
int a[MAX_N];

int amb[MAX_N];
int last[MAX_N], cnt[MAX_N];

int t[MAX_N], r[MAX_N];

int main(){

  scanf( "%d" , &test_case );
  REP( test_cnt , test_case ){
    scanf( "%d %d" , &m , &k );
    REP( i , k ) scanf( "%d" , &a[i] );
    
    REP( i , k ) cnt[i] = 0, last[i] = -1;
    REP( i , m ) amb[i] = 0;
    
    REP( i , m-1 ){
      scanf( "%d %d" , &t[i] , &r[i] ); t[i]--;
      amb[i+1] = amb[i];
      if( t[i] == -1 ){
	amb[i+1]++;
      } else {
	last[ t[i] ] = i;
	cnt[ t[i] ]++;
      }
    }

    int used_amb = INF;
    REP( i , m-1 ) if( r[i] == 1 ){
      REP( j , k ) if( last[j] < i && amb[i] + cnt[j] >= a[j] ){
	chmin( used_amb , a[j] - cnt[j] );
	a[j] = -INF;
      }
      break;
    }
    if( used_amb == INF ) used_amb = 0;

    int ambs = amb[m-1] - used_amb;
    
    REP( i , k ){
      if( ambs + cnt[i] >= a[i] ) printf( "Y" );
      else printf( "N" );
    }
    printf( "\n" );
  }
  
  return 0;
}