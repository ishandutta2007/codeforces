#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 2010;

ll n, k;
ll a[MAX_N];
ll dp[MAX_N];

bool check( ll x ){
  REP( i , n ) dp[i] = i;
  REP( i , n ) FOR( j , i+1 , n ) if( abs(a[i]-a[j]) <= (j-i)*x ) chmin( dp[j] , dp[i]+(j-i-1) );
  REP( i , n ) if( dp[i]+n-1-i <= k ) return true;
  return false;
}

int main(){

  scanf( "%lld %lld" , &n , &k );
  REP( i , n ) scanf( "%lld" , &a[i] );

  ll lb = -1, ub = INF*2;
  while( ub-lb > 1 ){
    ll md = (ub+lb)/2;
    if( check( md ) ) ub = md;
    else lb = md;
  }

  printf( "%lld\n" , ub );
  
  return 0;
}