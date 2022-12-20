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


const int MAX_N = 150010;
const int MAX_M = 310;

ll n, m;
ll d;
ll a[MAX_M], b[MAX_M], t[MAX_M];
ll ans = 0;

ll dp[2][MAX_N];

int main(){

  scanf( "%lld %lld %lld" , &n , &m , &d );
  REP( i , m ) scanf( "%lld %lld %lld" , &a[i] , &b[i] , &t[i] );


  FOR( i , 1 , n+1 ) dp[1][i] = abs( i - a[0] );

  FOR( i , 1 , m ){
    ll w = d*(t[i]-t[i-1]);
    deque<int> deq;
    FOR( j , 1 , min(w+1,n+1) ){
      while( !deq.empty() && dp[1][deq.back()] >= dp[1][j] ) deq.pop_back();
      deq.push_back( j );
    }
    FOR( j , 1 , n+1 ){
      if( w+j <= n ){
	while( !deq.empty() && dp[1][deq.back()] >= dp[1][w+j] ) deq.pop_back();
	deq.push_back( w+j );
      }
      dp[0][j] = dp[1][deq.front()] + abs( j - a[i] );
      if( deq.front() == j-w ) deq.pop_front();
    }
    swap( dp[0] , dp[1] );
  }

  REP( i , m ) ans += b[i];
  ll res = INFLL;
  FOR( j , 1 , n+1 ) chmin( res , dp[1][j] );

  printf( "%lld\n" , ans - res );
  
  return 0;
}