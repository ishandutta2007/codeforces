#include <bits/stdc++.h>
  
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())
#define SHOW(x) cout << #x << " = " << x << endl
 
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
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;
 
const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
// head

int n;
int a[4010];
int sum[4010];

int igormemo[4010][100][100];
int zhenyamemo[4010][100][100];

int igor( int l , int c , int z );
int zhenya( int l , int c , int z );

int igor( int l , int c , int z ){
  int &res = igormemo[l][c][z];
  if( res != -INF ){
    return res;
  }
  int r = l + z;

  bool f = false;
  if( l + r + c <= n ){
    f = true;
    chmax( res , zhenya( l + c , c , z ) + sum[ l + c ] - sum[l] );
  }
  if( l + r + c + 1 <= n ){
    f = true;
    chmax( res , zhenya( l + c + 1 , c + 1 , z ) + sum[ l + c + 1 ] - sum[l] );
  }

  if( !f ){
    res = 0;
  }
  
  return res;
}

int zhenya( int l , int c , int z ){
  int &res = zhenyamemo[l][c][z];
  if( res != INF ){
    return res;
  }
  int r = l - c + z;

  bool f = false;
  if( l + r + c <= n ){
    f = true;
    chmin( res , igor( l , c , z ) - ( sum[ n - r ] - sum[ n - r - c ] ) );
  }
  if( l + r + c + 1 <= n ){
    f = true;
    chmin( res , igor( l , c+1 , z+1 ) - ( sum[ n - r ] - sum[ n - r - c - 1 ] ) );
  }

  if( !f ){
    res = 0;
  }

  return res;
}

int main(){

  n = in();
  REP( i , n ){
    a[i] = in();
  }

  REP( i , n ){
    sum[i+1] = sum[i] + a[i];
  }
  
  REP( i , 4010 ){
    REP( j , 100 ){
      REP( k , 100 ){
	igormemo[i][j][k] = -INF;
	zhenyamemo[i][j][k] = INF;
      }
    }
  }

  printf( "%d\n" , igor( 0 , 1 , 0 ) );
  
  return 0;
}