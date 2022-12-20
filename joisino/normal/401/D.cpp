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

vl ds;
ll n, m;

ll dp[PW(18)][128];

int main(){

  scanf( "%lld %lld" , &n , &m );
  while( n > 0 ) ds.pb( n%10 ), n /= 10;
  
  REP( i , SZ(ds) ) if( ds[i] != 0 ) dp[PW(i)][ds[i]%m] = 1;

  REP( i , PW(SZ(ds)) ) REP( j , m ) if( dp[i][j] != 0 ){
    REP( k , SZ(ds) ) if( !( i & PW(k) ) ) dp[i|PW(k)][(j*10+ds[k])%m] += dp[i][j];
  }

  ll ans = dp[PW(SZ(ds))-1][0];
  REP( i , 10 ) FOR( j , 1 , count(ALL(ds),i)+1 ) ans /= j;
  
  printf( "%lld\n" , ans );
  
  
  return 0;
}