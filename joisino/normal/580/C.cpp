#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto x:arr)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
//typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }

const int MAX_N = 100010;

int n, m;
int a[MAX_N];

int ans;

vector<int> G[MAX_N];

void dfs( int x , int p , int cnt ){
  cnt += a[x];
  if( a[x] == 0 ) cnt = 0;
  if( cnt == m+1 ) return;
  if( p != -1 && G[x].size() == 1 ) ans++;
  REPR( w , G[x] )
    if( w != p )
      dfs( w , x , cnt );
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n )
    scanf( "%d" , &a[i] );
  REP( i , n-1 ){
    int x, y;
    scanf( "%d %d" , &x , &y ); x--; y--;
    G[x].pb( y );
    G[y].pb( x );
  }

  dfs( 0 , -1 , 0 );

  cout << ans << endl;
  
  return 0;
}