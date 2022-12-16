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

const int MAX_N = 100010;

ll n;
ll a[MAX_N];
ll sum[MAX_N];
ll q, k;

ll ans;

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );
  sort( a , a+n );
  reverse( a , a+n );

  REP( i , n ) sum[i+1] = sum[i] + a[i];

  REP( i , n ) ans += a[i] * (ll)i;
  
  scanf( "%lld" , &q );
  REP( i , q ){
    scanf( "%lld" , &k );
    if( k == 1 ) printf( "%lld" , ans );
    else{
      ll res = 0;
      ll p = 0;
      ll a = 1;
      ll c = 0;
      while( a <= n ){
	res += c * ( sum[a] - sum[p] );
	p = a;
	a = a * k + 1;
	c++;
      }
      res += c * (sum[n] - sum[p]);
      printf( "%lld" , res );
    }
    if( i == q-1 ) printf( "\n" );
    else printf( " " );
  }
  
  return 0;
}