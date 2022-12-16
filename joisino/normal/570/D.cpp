#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()1
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

const int MAX_N = 500010;

int n, m;
string s;

int h[MAX_N];
int res[MAX_N];

vector<int> G[MAX_N];
vector<int> Q[MAX_N];

int sum[MAX_N];
int dep[MAX_N];

int dfs( int x , int d ){
  REP( i , Q[x].size() )
    res[ Q[x][i] ] ^= sum[ h[ Q[x][i] ] ];
  
  sum[d] ^= 1<<(s[x]-'a');
  
  REP( i , G[x].size() )
    dfs( G[x][i] , d+1 );

  REP( i , Q[x].size() )
    res[ Q[x][i] ] ^= sum[ h[ Q[x][i] ] ];
}

int main(){

  scanf( "%d %d" , &n , &m );

  FOR( i , 1 , n ){
    int a;
    scanf( "%d" , &a );
    G[a-1].pb( i );
  }

  cin >> s;
  
  REP( i , m ){
    int a , b;
    scanf( "%d %d" , &a , &h[i] ); a--;
    Q[a].pb( i );
  }

  dfs( 0 , 1 );

  REP( i , m ){
    if( __builtin_popcount( res[i] ) <= 1 ) puts( "Yes" );
    else puts( "No" );
  }
  
  return 0;
}