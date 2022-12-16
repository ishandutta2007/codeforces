#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

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


const int MAX_N = 200010;

ll n , k;
ll a[MAX_N];

ll b[MAX_N] , f[MAX_N];

map<ll,ll> mpb , mpf;

int main(){

  cin >> n >> k;

  REP( i , n )
    cin >> a[i];

  REP( i , n ){
    if( a[i] % k == 0 )
      b[i] = mpb[ a[i]/k ];
    mpb[ a[i] ]++;
  }

  FOR( i , 1 , n+1 ){
    f[n-i] = mpf[ a[n-i]*k ];
    mpf[ a[n-i] ]++;
  }

  ll ans = 0;
  REP( i , n )
    ans += b[i] * f[i];

  cout << ans << endl;
  
  return 0;
}