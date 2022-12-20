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

const int MAX_N = 5010;

int n;

char G[MAX_N][MAX_N];
bool used[MAX_N];

int ans1, ans2, ans3;

void dfs( int x , int p ){
  used[x] = true;
  REP( i , n ) if( G[x][i] == '1' ){
    if( !used[i] ) dfs( i , x );
    else if( p != -1 && G[i][p] == '1' ){
      ans1 = x+1, ans2 = i+1, ans3 = p+1;
    }
  }
}


int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%s" , G[i] );
  REP( i , n ) if( !used[i] ) dfs( i , -1 );
  if( ans1 != 0 ) printf( "%d %d %d\n" , ans1 , ans2 , ans3 );
  else printf( "-1\n" );
  
  return 0;
}