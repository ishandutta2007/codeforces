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

const int MAX_N = 310;
const int dx[] = { 1 , 0 , 1 , 0 };
const int dy[] = { 0 , -1 , 0 , 1 };

int n, m, k;
int y, x;
int d = 3;
int cnt = 0;
int ck = 0;

vpi ans[MAX_N*MAX_N];

int main(){

  scanf( "%d %d %d" , &n , &m , &k );

  while( 1 ){
    ans[ck].pb( y , x );
    y += dy[d];
    x += dx[d];
    cnt++;
    if( cnt == 2 && ck+1 < k ){
      ck++;
      cnt = 0;
    }
    if( d == 0 || d == 2 ) d++;
    else if( y == 0 || y == n-1 ){
      d = (d+1)%4;
    }
    if( x >= m ) break;
  }

  REP( i , k ){
    printf( "%d" , (int)ans[i].size() );
    YYS( w , ans[i] ){
      printf( " %d %d" , w.fi+1 , w.se+1 );
    }
    printf( "\n" );
  }
  
  return 0;
}