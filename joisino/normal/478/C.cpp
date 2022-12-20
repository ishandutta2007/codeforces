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

ll ans;
ll a[3];

int main(){

  REP( i , 3 ) cin >> a[i];
  sort( a , a+3 );

  ll f = min( a[2]-a[1] , a[1]-a[0] );
  ans += f;
  a[2] -= f*2;
  a[1] -= f;

  if( a[1]==a[2] ){

    // *****
    // *****
    // **

    ll t = (a[2]-a[0])/3;
    ans += t*2;
    a[2] -= t*3;
    a[1] -= t*3;

    if( a[1]-a[0] >= 2 ){
      a[2] -= 1;
      a[1] -= 2;
      ans++;
    }
  } else {

    // ***
    // **
    // **

    ll t = min(a[1],(a[2]-a[1])/3);
    ans += t*2;
    a[2] -= t*4;
    a[1] -= t;
    a[0] -= t;
  }
  
  ans += a[0];

  cout << ans << endl;
  
  return 0;
}