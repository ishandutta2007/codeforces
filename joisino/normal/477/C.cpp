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

const int MAX_N = 2010;

string s, p;

int to[MAX_N];
int dp[MAX_N][MAX_N];
int ans[MAX_N];

int main(){

  cin >> s >> p;
  int n = s.length();
  int m = p.length();

  
  REP( i , n ) to[i] = INF;
  
  REP( i , n ){
    if( s[i] != p[0] ) continue;
    int c = 0;
    FOR( j , i , n ){
      if( s[j] == p[c] ) c++;
      if( c == m ){
	to[i] = j; break;
      }
    }
  }

  
  REP( i , MAX_N ) REP( j , MAX_N ) dp[i][j] = INF;
  dp[0][0] = 0;
  
  REP( i , n ){
    REP( j , n ){
      chmin( dp[i+1][j] , dp[i][j] );
      if( to[i] != INF ) chmin( dp[to[i]+1][j+1] , dp[i][j] + to[i]+1-i-m );
    }
  }


  REP( i , n+1 )
    if( dp[n][i] != INF ) ans[ dp[n][i] ] = i;
  FOR( i , 1 , n+1 )
    chmax( ans[i] , ans[i-1] );
  REP( i , n+1 )
    chmin( ans[i] , (n-i)/m );
    
  REP( i , n+1 ){
    if( i != 0 ) printf( " " );
    printf( "%d" , ans[i] );
  }
  printf( "\n" );
    
  
  return 0;
}