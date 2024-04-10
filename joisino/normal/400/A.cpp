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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

ll t;

char field[72][72];
char s[72];

bool check( ll a , ll b ){
  REP( i , 12 ) field[i/b][i%b] = s[i];
  REP( j , b ){
    bool ok = true;
    REP( i , a ) if( field[i][j] == 'O' ) ok = false;
    if( ok ) return true;
  }
  return false;
}

int main(){

  scanf( "%lld" , &t );
  REP( test_cnt , t ){
    scanf( "%s" , s );
    vpl ans(0);
    FOR( i , 1 , 13 ) if( 12 % i == 0 && check( i , 12/i ) ) ans.pb( i , 12/i );
    printf( "%lld" , SZ(ans) );
    YYS( w , ans ) printf( " %lldx%lld" , w.fi , w.se );
    printf( "\n" );
  }

  return 0;
}