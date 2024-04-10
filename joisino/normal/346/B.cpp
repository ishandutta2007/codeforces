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

const int MAX_N = 128;

char cs1[MAX_N]; string s1;
char cs2[MAX_N]; string s2;
char cev[MAX_N]; string ev;

typedef pair<int,pi> ipi;

int dp[MAX_N][MAX_N][MAX_N]; // p1 p2 pe
ipi pr[MAX_N][MAX_N][MAX_N];
int st[MAX_N];

string ans;

void update( int a , int b , int c , int d , int e , int f , int g ){
  if( dp[a][b][c] < dp[d][e][f] + g ){
    dp[a][b][c] = dp[d][e][f] + g;
    pr[a][b][c] = ipi( d , pi( e , f ) );
  }
}

int main(){

  scanf( "%s\n" , cs1 ); s1 = cs1;
  scanf( "%s\n" , cs2 ); s2 = cs2;
  scanf( "%s\n" , cev ); ev = cev;

  st[0] = -1;
  REP( i , ev.length() ) FOR( j , 1 , i ){
    bool ok = true;
    REP( k , i-j ) ok &= ev[k] == ev[j+k];
    if( ok ){
      st[i] = i-j;
      break;
    }
  }

  REP( i , MAX_N ) REP( j , MAX_N ) REP( k , MAX_N ) dp[i][j][k] = -INF;
  dp[0][0][0] = 0;
  
  REP( i , s1.length()+1 ) REP( j , s2.length()+1 ) REP( k , ev.length() ){
    //cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
    if( i < s1.length() && j < s2.length() && s1[i] == s2[j] ){
      update( i+1 , j+1 , k , i , j , k , 0 );
      if( ev[k] == s1[i] ){
	update( i+1 , j+1 , k+1 , i , j , k , 1 );
      } else {
	int nk = st[k];
	while( nk != -1 && ev[nk] != s1[i] ) nk = st[nk];
	update( i+1 , j+1 , nk+1 , i , j , k , 1 );
      }
    } else {
      update( i+1 , j , k , i , j , k , 0 );
      update( i , j+1 , k , i , j , k , 0 );
    }
  }

  int x = s1.length(), y = s2.length() , z = 0;
  REP( i , ev.length() ) if( dp[x][y][z] < dp[x][y][i] ) z = i;

  /*
  REP( i , ev.length() ) cout << dp[x][y][i] << endl;
  return 0;
  */

  while( x > 0 && y > 0 ){
    int nx = pr[x][y][z].fi;
    int ny = pr[x][y][z].se.fi;
    int nz = pr[x][y][z].se.se;
    if( dp[nx][ny][nz] + 1 == dp[x][y][z] ) ans += s1[nx];
    x = nx;
    y = ny;
    z = nz;
  }

  REVERSE( ans );
  if( ans.length() > 0 ) printf( "%s\n" , ans.c_str() );
  else puts( "0" );
  
  return 0;
}