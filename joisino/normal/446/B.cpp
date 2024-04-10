#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1010;

ll n, m, k, p;
priority_queue<ll> que;
ll cntc, cntr;
ll a[MAX_N][MAX_N];
ll x[2][1000010];

int main(){

  scanf( "%lld %lld %lld %lld" , &n , &m , &k , &p );
  REP( i , n ) REP( j , m ) scanf( "%lld" , &a[i][j] );

  REP( l , 2 ){
    while( !que.empty() ) que.pop();
    REP( i , n ){
      ll sum = 0;
      REP( j , m )
	sum += a[i][j];
      que.push( sum );
    }

    ll ans = 0;
    REP( i , k ){
      x[l][i+1] = x[l][i] + que.top();
      que.push( que.top() - p * m );
      que.pop();
    }

    REP( i , max(n,m) ) REP( j , i ) swap( a[i][j] , a[j][i] );
    swap( n , m );
  }

  ll ans = -INFLL;
  REP( i , k+1 )
    chmax( ans , x[0][i] + x[1][k-i] - ( p * (ll)i * (ll)(k-i) ) );

  printf( "%lld\n" , ans );
  
  return 0;
}