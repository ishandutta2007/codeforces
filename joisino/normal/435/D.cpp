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

const int MAX_N = 410;

int n, m;
char s[MAX_N][MAX_N];
int a[MAX_N][MAX_N];

int rsum[MAX_N][MAX_N];
int csum[MAX_N][MAX_N];
int msum[MAX_N*2][MAX_N*2];
int hsum[MAX_N*2][MAX_N*2];

ll ans = 0;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%s" , s[i] );
  REP( i , n ) REP( j , m ) a[i][j] = s[i][j]-'0';

  REP( i , n ) REP( j , m ){
    rsum[i][j+1] = rsum[i][j] + a[i][j];
    csum[i+1][j] = csum[i][j] + a[i][j];
    msum[i+1][j-i+MAX_N] = msum[i][j-i+MAX_N] + a[i][j];
    hsum[i+1][j+i] = hsum[i][j+i] + a[i][j];
  }

  int xa, ya, xb, yb;
  REP( i , n ) REP( j , m ){
    if( a[i][j] == 1 ) continue;
    
    xa = j-1, ya = i, xb = j, yb = i-1;
    while( xa >= 0 && yb >= 0 && a[ya][xa] != 1 && a[yb][xb] != 1 ){
      if( hsum[ya][xa+ya] == hsum[yb][xb+yb] ) ans++;
      xa--; yb--;
    }
	
    xa = j-1, ya = i-1, xb = j+1, yb = i-1;
    while( xa >= 0 && ya >= 0 && xb < m && yb >= 0 && a[ya][xa] != 1 && a[yb][xb] != 1 ){
      if( rsum[yb][xb] == rsum[ya][xa] ) ans++;
      xa--; ya--; xb++; yb--;
    }

    xa = j+1, ya = i, xb = j, yb = i-1;
    while( xa < m && yb >= 0 && a[ya][xa] != 1 && a[yb][xb] != 1 ){
      if( msum[ya][xa-ya+MAX_N] == msum[yb][xb-yb+MAX_N] ) ans++;
      xa++; yb--;
    }
    
    xa = j+1, ya = i-1, xb = j+1, yb = i+1;
    while( xa < m && ya >= 0 && xb < m && yb < n && a[ya][xa] != 1 && a[yb][xb] != 1 ){
      if( csum[yb][xb] == csum[ya][xa] ) ans++;
      xa++; ya--; xb++; yb++;
    }

    xa = j+1, ya = i, xb = j, yb = i+1;
    while( xa < m && yb < n && a[ya][xa] != 1 && a[yb][xb] != 1 ){
      if( hsum[ya][xa+ya] == hsum[yb][xb+yb] ) ans++;
      xa++; yb++;
    }

    xa = j+1, ya = i+1, xb = j-1, yb = i+1;
    while( xa < m && ya < n && xb >= 0 && yb < n && a[ya][xa] != 1 && a[yb][xb] != 1 ){
      if( rsum[yb][xb] == rsum[ya][xa] ) ans++;
      xa++; ya++; xb--; yb++;
    }

    xa = j-1, ya = i, xb = j, yb = i+1;
    while( xa >= 0 && yb < n && a[ya][xa] != 1 && a[yb][xb] != 1 ){
      if( msum[ya][xa-ya+MAX_N] == msum[yb][xb-yb+MAX_N] ) ans++;
      xa--; yb++;
    }


    xa = j-1, ya = i+1, xb = j-1, yb = i-1;
    while( xa >= 0 && ya < n && xb >= 0 && yb >= 0 && a[ya][xa] != 1 && a[yb][xb] != 1 ){
      if( csum[yb][xb] == csum[ya][xa] ) ans++;
      xa--; ya++; xb--; yb--;
    }
    
  }

  printf( "%lld\n" , ans );
  
  return 0;
}