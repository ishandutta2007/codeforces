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

const int MAX_N = 100010;

ll n, k;
ll d[MAX_N];
ll deg[MAX_N];

vpl ds;
queue<ll> que;

vpl ans;

int ng(){
  printf( "-1\n" );
  return 0;
}

int main(){

  scanf( "%lld %lld" , &n , &k );
  REP( i , n ) scanf( "%lld" , &d[i] );
  REP( i , n ) ds.pb( d[i] , i );
  SORT( ds );
  
  if( ds[0].fi == 0 ) que.push( ds[0].se );
  else return ng();
  
  FOR( i , 1 , n ){
    while( !que.empty() && d[que.front()]+1 != ds[i].fi ) que.pop();
    if( que.empty() ) return ng();
    ans.pb( que.front() , ds[i].se );
    deg[ que.front() ]++;
    if( deg[que.front()] == k ) que.pop();
    deg[ ds[i].se ]++;
    if( deg[ ds[i].se ] != k ) que.push( ds[i].se );
  }

  printf( "%lld\n" , SZ(ans) );
  YYS( w , ans ) printf( "%lld %lld\n" , w.fi+1 , w.se+1 );
  
  return 0;
}