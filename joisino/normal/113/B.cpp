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

const int MAX_LHM = 2;
const ll MUL[2] = { 72727 , 51419 };
const ll RHMOD[2] = { 765876961 , 727272727 };
struct RollingHash{
  vl h[MAX_LHM];
  vl e[MAX_LHM];
  int n;
  void init( const string &s ){
    n = s.length();
    
    REP( j , MAX_LHM ){
      h[j] = vl( n+1 , 0 );
      e[j] = vl( n+1 , 1 );
    }

    REP( i , n )
      REP( j , MAX_LHM )
	h[j][i+1] = ( h[j][i] * MUL[j] + s[i] ) % RHMOD[j];

    REP( j , MAX_LHM )
      REP( i , n )
	e[j][i+1] = e[j][i] * MUL[j] % RHMOD[j];
  }
  RollingHash(){}
  RollingHash( const string &s ){
    init( s );
  }
  ll get( int s , int t ){
    chmin( s , n ); chmax( s , 0 );
    chmin( t , n ); chmax( t , 0 );
    ll res;
    res = ( h[0][t] - h[0][s] * e[0][t-s] % RHMOD[0] + RHMOD[0] ) % RHMOD[0];
    res += ( ( h[1][t] - h[1][s] * e[1][t-s] % RHMOD[1] + RHMOD[1] ) % RHMOD[1] ) * (ll)INF;
    return res;
  }
};

const int MAX_N = 2010;

char s[MAX_N];
char st[MAX_N], en[MAX_N];

vl ss;

int main(){

  scanf( "%s%s%s" , s , st , en );
  int n = strlen( s );
  int stn = strlen( st );
  int enn = strlen( en );

  RollingHash rh( s );
  ll sth = RollingHash( st ).get( 0 , stn );
  ll enh = RollingHash( en ).get( 0 , enn );

  REP( i , n ) if( i+stn <= n && rh.get( i , i+stn ) == sth ){
    FOR( j , i , n ) if( j+enn >= i+stn && j+enn <= n && rh.get( j , j+enn ) == enh ) ss.pb( rh.get( i , j+enn ) );
  }
  SORT( ss );
  UNIQUE( ss );

  cout << ss.size() << endl;
  
  return 0;
}