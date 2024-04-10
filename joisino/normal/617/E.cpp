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

const ll INF = 1e9+10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 2000010;
const int B = 765;

typedef pair<int,pi> qs;

int n, m, k;
int a[MAX_N], sum[MAX_N];
ll ans[MAX_N];
ll cnt[MAX_N];
ll res;

vector<qs> query;

bool cmp( const qs &a , const qs &b ){
  if( a.se.fi / B != b.se.fi / B ) return a.se.fi / B < b.se.fi / B;
  return a.se.se < b.se.se;
}

void add( int x ){
  res += cnt[x^k];
  cnt[x]++;
}

void del( int x ){
  cnt[x]--;
  res -= cnt[x^k];
}

int main(){

  scanf( "%d %d %d" , &n , &m , &k );
  REP( i , n ) scanf( "%d" , &a[i] );
  REP( i , n ) sum[i+1] = sum[i] ^ a[i];
  REP( i , m ){
    int l, r;
    scanf( "%d %d" , &l , &r ); l--; r++;
    query.pb( i , pi( l , r ) );
  }

  sort( ALL(query) , cmp );

  int l = 0, r = 0;
  YYS( w , query ){
    int ql = w.se.fi, qr = w.se.se;
    while( qr < r ) del( sum[--r] );
    while( r < qr ) add( sum[r++] );
    while( ql < l ) add( sum[--l] );
    while( l < ql ) del( sum[l++] );
    ans[w.fi] = res;
  }

  REP( i , m ) printf( "%lld\n" , ans[i] );
  
  return 0;
}