#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())

#define pb emplace_back
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
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 5010;
const int MAX_A = 1000010;

int n, k;

int a[MAX_N], c[MAX_A];
int used[MAX_A];

int main(){
  
  scanf( "%d %d" , &n , &k );
  REP( i , n ) scanf( "%d" , &a[i] );
  sort( a , a+n );
  REP( i , n ) REP( j , i ) c[ a[i] - a[j] ]++;
  
  FOR( ans , 1 , INF ){
    int res = 0;
    for( int i = ans; i < MAX_A; i += ans ) res += c[i];
    if( res <= k*(k+1)/2 ){
      res = 0;
      REP( i , n ){
	if( used[a[i]%ans] != ans ) used[a[i]%ans] = ans;
	else res++;
      }
      if( res <= k ){
	printf( "%lld\n" , ans );
	return 0;
      }
    }
  }
  
  return 0;
}