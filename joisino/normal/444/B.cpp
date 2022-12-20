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

const int MAX_N = 100010;

ll a[MAX_N], b[MAX_N];
ll n, d, x;

ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    for( int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for( int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for( int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for( int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}


int main(){

  scanf( "%lld %lld %lld" , &n , &d , &x );
  initAB();

  if( d < 500 ){
    vi x;
    REP( i , n ){
      if( b[i] == 1 ) x.pb( i );
      ll ans = 0;
      REPR( w , x )
	chmax( ans , a[i-w] );
      printf( "%lld\n" , ans );
    }
  } else {
    set<pi> ss;
    REP( i , n ){
      ss.insert( pi( a[i] , i ) );
      ll ans = 0;
      for( auto ite = ss.rbegin(); ite != ss.rend(); ite++ ){
	if( b[ i - (*ite).se ] ){
	  ans = (*ite).fi; break;
	}
      }
      printf( "%lld\n" , ans );
    }
  }
  
  return 0;
}