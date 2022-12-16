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

const int MAX_N = 100010;

int a[MAX_N];
int x[MAX_N];
int y[MAX_N];

int main(){

  int n = in();

  REP( i , n )
    cin >> a[i];

  x[0] = min( a[0] , 1 );
  FOR( i , 1 , n )
    x[i] = min( x[i-1]+1 , a[i] );

  y[n-1] = min( a[n-1] , 1 );
  FOR( i , 2 , n+1 )
    y[n-i] = min( y[n-i+1]+1 , a[n-i] );

  int ans = 0;
  REP( i , n )
    chmax( ans , min( x[i] , y[i] ) );

  cout << ans << endl;
  
  return 0;
}