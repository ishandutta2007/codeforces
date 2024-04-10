#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
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

const int MAX_N = 128;

int n;
vl v;
ll a;
ll ans;

int main(){

  scanf( "%d" , &n );
  REP( i , n ){
    scanf( "%lld" , &a );
    int m = v.size();
    while( m >= 2 && v[m-2] >= v[m-1] && v[m-1] <= a ){
      ans += min( a , v[m-2] );
      v.pop_back();
      m = v.size();
    }
    v.pb( a );
  }

  SORT( v );
  REVERSE( v );

  FOR( i , 2 , v.size() )
    ans += v[i];

  printf( "%lld\n" , ans );
  
  return 0;
}