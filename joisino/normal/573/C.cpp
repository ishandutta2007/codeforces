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
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }


const int MAX_N = 100010;

vec G[MAX_N];
bool ans = true;
int a[MAX_N];

int dfs( int x , int p ){
  REPR( w , G[x] )
    if( w != p )
      a[x] += dfs( w , x );
  return a[x] + ( G[x].size() >= 3 ? 1 : 0 );
}

void dfs2( int x , int p , bool t ){
  int res = 0;

  if( p != -1 )
    if( G[p].size() >= 4 || t ) res++;

  REPR( w , G[x] )
    if( w != p )
      if( G[w].size() >= 4 || a[w] >= 1 ) res++;

  if( res >= 3 ) ans = false;

  REPR( w , G[x] )
    if( w != p )
      dfs2( w , x , t || ( p != -1 && G[p].size() >= 3 ) || a[x] - ( a[w] + ( G[w].size() >= 3 ? 1 : 0 ) ) >= 1 );
}


int main(){

  int n = in();

  REP( i , n-1 ){
    int a , b;
    cin >> a >> b; a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  dfs( 0 , -1 );
  dfs2( 0 , -1 , false );

  if( ans ) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}