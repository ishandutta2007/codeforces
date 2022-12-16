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
const ll MOD = 1000000009;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int n;
ll h;

pl a[MAX_N];

int main(){

  scanf( "%d %lld" , &n , &h );
  REP( i , n ) scanf( "%lld" , &a[i].fi );
  REP( i , n ) a[i].se = i;
  sort( a , a+n );

  ll res1 = a[n-2].fi + a[n-1].fi - ( a[0].fi + a[1].fi );
  ll res2 = max( a[n-2].fi + a[n-1].fi , a[n-1].fi + a[0].fi + h ) - min( a[0].fi + a[1].fi + h , a[1].fi + a[2].fi );

  printf( "%lld\n" , min( res1 , res2 ) );
  REP( i , n ){
    if( res1 > res2 && i == a[0].se ) printf( "2%c" , i == n-1 ? '\n' : ' ' );
    else printf( "1%c" , i == n-1 ? '\n' : ' ' );
  }
  
  
  return 0;
}