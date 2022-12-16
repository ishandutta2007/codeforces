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
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


const int MAX_N = 200010;
const int MAX_A = 1000010;

int n;
ll a[MAX_N];
ll dp[MAX_A*2];
ll ans;

int main(){

  cin >> n;
  REP( i , n ) cin >> a[i];
  REP( i , n ) dp[ a[i] ] = a[i];
  FOR( i , 1 , MAX_A*2 ) chmax( dp[i] , dp[i-1] );

  sort( a , a+n );
  REP( i , n ){
    if( i != 0 && a[i-1] == a[i] ) continue;
    for( ll j = a[i]*2-1; j < MAX_A*2; j += a[i] )
      chmax( ans , dp[j]%a[i] );
  }

  cout << ans << endl;

  return 0;
}