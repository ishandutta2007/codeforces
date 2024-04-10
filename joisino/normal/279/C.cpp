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

const int MAX_N = 100010;

int n, m;
ll a[MAX_N];
int u[MAX_N];
int d[MAX_N];

int main(){

  cin >> n >> m;

  REP( i , n )
    cin >> a[i];

  vec b;
  b.pb( 0 );
  FOR( i , 1 , n ){
    if( a[i-1] > a[i] ){
      REP( j , b.size() )
	u[ b[j] ] = i-1;
      b.clear();
    }
    b.pb( i );
  }
  REP( j , b.size() )
    u[ b[j] ] = n-1;
  b.clear();

  b.pb( 0 );
  FOR( i , 1 , n ){
    if( a[i-1] < a[i] ){
      REP( j , b.size() )
	d[ b[j] ] = i-1;
      b.clear();
    }
    b.pb( i );
  }
  REP( j , b.size() )
    d[ b[j] ] = n-1;
  b.clear();

  /*
  REP( i , n )
    cout << i << " " << u[i] << " " << d[i] << endl;
  */

  REP( loop , m ){
    int x, y;
    cin >> x >> y; x--; y--;
    if(  d[ u[ x ] ] >= y ) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  
  return 0;
}