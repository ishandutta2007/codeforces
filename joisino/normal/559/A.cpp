#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
 
const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }
 
#define fi first
#define se second

typedef pair<ll,ll> P;
typedef vector<ll> vec;

ll a[6];

int main(){

  REP( i , 6 )
    cin >> a[i];

  ll f = 0;
  ll b = 0;
  ll da = 2 * a[0] - 1;
  ll ans = 0;

  while( 1 ){
    if( a[1+f] == 0 ){
      f++;
      da++;
    }
    if( a[5-b] == 0 ){
      b++;
      da++;
    }
    if( f == 2 && b == 2 ) break;
    da += 2 - (f+b)*2;
    ans += da;
    a[1+f]--;
    a[5-b]--;
  }

  cout << ans << endl;

  return 0;
}