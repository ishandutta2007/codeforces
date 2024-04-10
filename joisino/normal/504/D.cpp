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
typedef vector<vi> mi;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const ll MAX_N = 2040;

bitset<MAX_N> x;

ll n;
char cs[MAX_N];

bitset<MAX_N> repr[MAX_N], base[MAX_N];
ll base_id[MAX_N];

void convert(){
  const ll B = 9;
  x = 0;
  string s = string( B - ( strlen(cs) % B ) , '0' ) + cs;
  ll sz = SZ(s);
  vl temp( sz / B );
  REP( i , sz ) temp[i/B] = temp[i/B] * 10 + (s[i] - '0');
  ll b = 1;
  REP( i , B ) b *= 10;

  REP( cnt , MAX_N / 30 ){
    REP( i , sz/B-1 ){
      temp[i+1] += b * ( temp[i] & ( PW(30) - 1 ) );
      temp[i] >>= 30;
    }
    REP( i , 30 ) x[cnt*30+i] = ( temp[sz/B-1] >> i ) & 1;
    temp[sz/B-1] >>= 30;
  }
}

void solve( ll id ){
  bitset<MAX_N> res = 0;
  REP( i , MAX_N ) if( x[i] ){
    if( base_id[i] == -1 ){
      base_id[i] = id;
      res[id] = 1;
      repr[id] = res;
      base[id] = x;
      printf( "0\n" );
      return;
    } else {
      x ^= base[ base_id[i] ];
      res ^= repr[ base_id[i] ];
    }
  }
  
  vl ans(0);
  REP( i , MAX_N ) if( res[i] ) ans.pb( i );
  printf( "%lld" , SZ(ans) );
  YYS( w , ans ) printf( " %lld" , w );
  printf( "\n" );
}

int main(){

  REP( i , MAX_N ) base_id[i] = -1;
  
  scanf( "%lld" , &n );
  REP( query_cnt , n ){
    scanf( "%s" , cs );
    convert();
    solve( query_cnt );
  }
  
  return 0;
}