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

ll mask_to_luckynumber( int mask ){
  ll base = 1;
  ll res = 0;
  bool end = false;
  REP( i , 10 ){
    if( mask % 3 == 0 ) end = true;
    else if( end ) return INFLL;
    
    if( mask % 3 == 1 ) res += base * 4;
    if( mask % 3 == 2 ) res += base * 7;
    base *= 10;
    mask /= 3;
  }
  return res;
}


ll fact[72];

int n;
ll k;
bool used[72];
int res[72];

int main(){

  fact[0] = 1;
  FOR( i , 1 , 16 ) fact[i] = fact[i-1] * i;

  cin >> n >> k;

  if( n < 16 && fact[n] < k ) return puts( "-1" );

  if( n < 4 ) return puts( "0" );
  if( n < 7 ){
    vi v(0);
    REP( i , n ) v.pb( i );
    do{
      k--;
      if( k == 0 ) break;
    } while( next_permutation( ALL(v) ) );
    if( v[3] == 3 ) return puts( "1" );
    return puts( "0" );
  }

  REP( i , min(n,15) ){
    int p = 0;
    while( used[p] ) p++;
    while( k > fact[min(n,15)-1-i] ){
      k -= fact[min(n,15)-1-i];
      p++;
      while( used[p] ) p++;
    }
    res[i] = p;
    used[p] = true;
  }

  // REP( i , 15 ) cout << i << " " << res[i] << endl;

  int ans = 0;

  ll e = 1;
  REP( i , 10 ) e *= 3;

  vi v;
  FOR( mask , 1 , e ){
    ll lucky = mask_to_luckynumber( mask );
    if( lucky == INFLL ) continue;
    if( lucky < n - 14 ) ans++;
    else if( lucky <= n ) v.pb( lucky );
  }

  YYS( w , v ) YYS( ww , v ) if( res[min(n,15)-1-(n-w)] == min(n,15)-1-(n-ww) ) ans++;

  cout << ans << endl;
  
  return 0;
}