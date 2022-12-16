#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


int main(){

  ll x1, y1;
  ll x2, y2;
  int n;

  cin >> x1 >> y1 >> x2 >> y2;

  int ans = 0;
  
  cin >> n;
  REP( i , n ){
    ll a, b, c;
    cin >> a >> b >> c;
    ll r1 = a * x1 + b * y1 + c;
    ll r2 = a * x2 + b * y2 + c;
    if( r1 < 0 && r2 > 0 ) ans++;
    if( r1 > 0 && r2 < 0 ) ans++;
  }

  cout << ans << endl;

  return 0;
}