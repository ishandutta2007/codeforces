#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
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

const int MAX_N = 500010;

int n;
int a[MAX_N];
int b[MAX_N];

int main(){

  scanf( "%d" , &n );

  REP( i , n )
    scanf( "%d" , &a[i] );

  FOR( i , 1 , n-1 )
    if( a[i] != a[i-1] && a[i] != a[i+1] )
      b[i] = b[i-1] + 1;

  for( int i = n-2; i >= 1; i-- )
    if( b[i] >= 1 )
      chmax( b[i] , b[i+1] );

  /*
  REP( i , n )
    cout << b[i] << " ";
  cout << endl;
  */
  
  int ans = 0;
  REP( i , n )
    chmax( ans , (b[i]+1)/2 );

  REP( i , n ){
    if( b[i] >= 1 ){
      if( b[i-1] == 0 ){
	REP( k , (b[i]+1)/2 )
	  a[i+k] = a[i-1];
      }
      if( b[i+1] == 0 ){
	REP( k , (b[i]+1)/2 )
	  a[i-k] = a[i+1];
      }
    }
  }

  printf( "%d\n" , ans );
  REP( i , n ){
    if( i != 0 ) printf( " " );
    printf( "%d" , a[i] );
  }
  printf( "\n" );
  
  return 0;
}