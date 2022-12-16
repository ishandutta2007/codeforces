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

const ll MAX_N = 128;

ll is[256];

char s[MAX_N];
ll cnt[3];
ll hav[3], per[3];
ll r;

bool check( ll a ){
  ll res = r;
  REP( i , 3 ) res -= max( 0LL , cnt[i] * a - hav[i] ) * per[i];
  return res >= 0;
}

int main(){

  is['B'] = 0; is['S'] = 1; is['C'] = 2;
  
  scanf( "%s" , s );
  ll n = strlen( s );
  REP( i , n ) cnt[ is[s[i]] ]++;
  REP( i , 3 ) scanf( "%lld" , &hav[i] );
  REP( i , 3 ) scanf( "%lld" , &per[i] );
  scanf( "%lld" , &r );

  ll lb = 0, ub = (ll)1e13;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( check( md ) ) lb = md;
    else ub = md;
  }

  printf( "%lld\n" , lb );
  
  return 0;
}