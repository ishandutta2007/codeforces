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

const int dx[] = { 1 , 0 , -1 , 0 };
const int dy[] = { 0 , 1 , 0 , -1 };

int main(){

  int gx, gy;
  cin >> gx >> gy;

  if( gx == 0 && gy == 0 ){
    cout << 0 << endl;
    return 0;
  }

  int k = 0;
  int x = 0;
  int y = 0;
  int ans = 0;

  int res = 1;
  
  while( 1 ){
    x += dx[k];
    y += dy[k];
    res--;
    if( x == gx && y == gy ) break;
    if( res == 0 ){
      k = (k+1)%4;
      ans++;
      res = ans/2+1;
    }
  }

  cout << ans << endl;
  
  return 0;
}