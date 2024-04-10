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
const ld EPS = 1e-10;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<class T> inline T sq( T a ){ return a * a; }

// head

const int MAX_N = 1000010;

int n;
int a[MAX_N];

bool used[MAX_N];

bool pooling[MAX_N];
vi ss[MAX_N];

int ans[MAX_N];

vi split( int x ){
  vi res = { x };
  int cur = a[x];
  while( cur != x ){
    res.pb( cur );
    cur = a[cur];
  }
  return res;
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] ), a[i]--;

  REP( i , n ) if( !used[i] ){
    vi res = split( i );

    /*
    cout << i << endl;
    YYS( w , res ) cout << w << " ";
    cout << endl;
    */
    
    YYS( w , res ) used[w] = true;
    int m = SZ(res);
    if( m % 2 == 1 ){
      REP( i , m/2 ){
	ans[res[i]] = res[i+m/2+1];
	ans[res[i+m/2+1]] = res[i+1];
      }
      ans[res[m/2]] = res[0];
    } else {
      if( !pooling[m] ){
	pooling[m] = true;
	ss[m] = res;
      } else {
	REP( i , m ) ans[res[i]] = ss[m][i], ans[ss[m][i]] = res[(i+1)%m];
	pooling[m] = false;
      }
    }
  }

  REP( i , MAX_N ) if( pooling[i] ){
    puts( "-1" );
    return 0;
  }

  REP( i , n ) printf( "%d%c" , ans[i]+1 , i == n-1?'\n':' ' );

  return 0;
}