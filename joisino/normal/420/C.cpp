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
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

int n, p;

int s[300010];

map<int,int> ma;

vi G[300010];
int deg[300010];

int main(){

  n = in();
  p = in();
  REP( i , n ){
    int a = in() - 1;
    int b = in() - 1;
    G[a].pb( b );
    G[b].pb( a );
    deg[a]++;
    deg[b]++;
  }

  REP( i , n ){
    s[ deg[i] + 1 ]++;
  }

  REP( i , n ){
    s[i+1] += s[i];
  }

  ll ans = 0;
  REP( i , n ){
    ans += n - s[ max( 0 , p - deg[i] ) ];
    if( deg[i] >= max( 0 , p - deg[i] ) ){
      ans--;
    }
    ma.clear();
    YYS( w , G[i] ){
      if( ma.find( w ) == ma.end() ){
        ma[w] = 1;
      } else {
        ma[w] = ma[w] + 1;
      }
    }
    YYS( w , ma ){
      if( deg[w.fi] >= max( 0 , p - deg[i] ) && deg[w.fi] - w.se < max( 0 , p - deg[i] ) ){
        ans--;
      }
    }
  }

  cout << ans / 2 << endl;

  return 0;
}