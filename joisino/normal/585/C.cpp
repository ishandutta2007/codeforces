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
const double EPS = 1e-7;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }

const int MAX_N = 300010;

typedef pair<ll,char> IC;

int main(){

  ll x, y;
  cin >> x >> y;
  if( __gcd( x , y ) != 1 ){
    cout << "Impossible" << endl;
    return 0;
  }

  vector<IC> ans;
  while( x >= 2 || y >= 2 ){
    if( x < y ){
      ll a = ( y - 1 ) / x;
      ans.pb( mp( a , 'B' ) );
      y -= a * x;
    } else {
      ll a = ( x - 1 ) / y;
      ans.pb( mp( a , 'A' ) );
      x -= a * y;
    }
  }

  REP( i , ans.size() )
    cout << ans[i].fi << ans[i].se;
  cout << endl;
  
  return 0;
}