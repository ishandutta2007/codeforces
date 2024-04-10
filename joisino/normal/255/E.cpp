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

const ll MAX_N = 1000010;

ll n;
ll a[MAX_N];

ll ans;

ll grandy[MAX_N];

set<ll> ss;
ll cnt[MAX_N];
ll s = 1, t = 1;

void add( ll x ){
  cnt[x]++;
  if( cnt[x] == 1 ) ss.erase( x );
}

void del( ll x ){
  cnt[x]--;
  if( cnt[x] == 0 ) ss.insert( x );
}

int main(){

  REP( i , MAX_N ) ss.insert( i );

  grandy[1] = 0;
  FOR( i , 2 , MAX_N ){
    while( t*t <= i ) add( grandy[t++] );
    while( s*s*s*s < i ) del( grandy[s++] );
    grandy[i] = *ss.begin();
  }

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );

  REP( i , MAX_N ) ss.insert( i );
  s = t = 0;
  REP( i , MAX_N ) cnt[i] = 0;
  
  sort( a , a+n );
  REP( i , n ){
    if( a[i] == 1 ) continue;
    while( t*t <= a[i] ) add( grandy[t++] );
    while( s*s*s*s < a[i] ) del( grandy[s++] );
    ans ^= *ss.begin();
  }

  if( ans == 0 ) printf( "Rublo\n" );
  else printf( "Furlo\n" );
  
  return 0;
}