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

const int MAX_N = 1010;

int n, k;

int res[MAX_N];
int ans;

int a[10][MAX_N];

int p[10][MAX_N];

int main(){

  scanf( "%d %d" , &n , &k );
  REP( i , k ) REP( j , n ) scanf( "%d" , &a[i][j] );

  REP( i , n ){
    FOR( j , 1 , k ) REP( l , n ) if( a[j][l] == a[0][i] ) p[j][i] = l;
    res[i] = 1;
    REP( l , i ){
      bool ok = true;
      FOR( j , 1 , k ) if( p[j][l] > p[j][i] ) ok = false;
      if( ok ) chmax( res[i] , res[l] + 1 );
    }
    chmax( ans , res[i] );
  }

  cout << ans << endl;
  
  return 0;
}