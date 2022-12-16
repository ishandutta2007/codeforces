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

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int n;
int a[MAX_N];

int cnt[MAX_N];

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );
  sort( a , a+n );

  int minv = a[0];
  int maxv = a[n-1];

  if( maxv - minv >= MAX_N ) return puts( "NO" );

  int m = maxv - minv;
  REP( i , n ) cnt[ a[i] - minv ]++;

  cnt[0]--;
  cnt[m]--;
  FOR( i , 1 , m ){
    if( cnt[i] < 2 ) return puts( "NO" );
    cnt[i] -= 2;
  }

  REP( i , m+1 ){
    if( cnt[i+1] < cnt[i] ) return puts( "NO" );
    cnt[i+1] -= cnt[i];
    cnt[i] = 0;
  }

  puts( "YES" );


  return 0;
}