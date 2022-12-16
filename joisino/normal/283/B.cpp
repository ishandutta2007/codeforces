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

const int MAX_N = 200010;

int n;
bool used[MAX_N][2];
ll a[MAX_N];
ll memo[MAX_N][2];

ll rec( int p , int d ){
  if( p == 0 ) return -INFLL;
  if( p < 0 || p >= n ) return 0;
  if( memo[p][d] != 0 ) return memo[p][d];
  if( used[p][d] ) return memo[p][d] = -INFLL;
  used[p][d] = true;
  ll res = rec( p + (2*d-1) * a[p] , d^1 ) + a[p];
  used[p][d] = false;
  return memo[p][d] = res;
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%lld" , &a[i+1] );

  FOR( i , 1 , n ){
    ll res = rec( i , 0 ) + i;
    if( res >= 0 ) printf( "%lld\n" , res );
    else printf( "-1\n" );
  }
  
  return 0;
}