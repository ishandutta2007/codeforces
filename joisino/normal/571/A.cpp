#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
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

ll a, b, c, l;
ll ans;

ll imp(){
  for( ll i = 0; i <= l; i++ ){
    ll j = min( l - i , a + i - b - c );
    if( j >= 0 ) ans -= (j+2)*(j+1)/2;
  }
}

int main(){

  cin >> a >> b >> c >> l;

  ans = (l+3)*(l+2)*(l+1)/6;
  
  imp();
  swap( a , b );
  imp();
  swap( a , c );
  imp();

  cout << ans << endl;
  
  return 0;
}