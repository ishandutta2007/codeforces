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

ll cross( pl a , pl b ){
  return a.fi * b.se - a.se * b.fi;
}

ll ccw( pl a , pl b , pl c ){
  pl nb = pl( ( a.fi - b.fi ) * c.fi * b.se , a.se - b.se );
  pl nc = pl( ( a.fi - c.fi ) * b.fi * c.se , a.se - c.se );
  if( cross( nb , nc ) > 0 ) return +1;
  if( cross( nb , nc ) < 0 ) return -1;
  return 0;
}

const ll MAX_N = 200010;

typedef pair<pl,ll> st;

ll n;
st v[MAX_N];
st ch[MAX_N];

vl ans;

set<pl> ss;

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld %lld" , &v[i].fi.fi , &v[i].fi.se );
  REP( i , n ) v[i].se = i;

  sort( v , v+n );
  reverse( v , v+n );
  ll k = 0;
  for( ll i = 0; i < n; ch[k++] = v[i++] )
    while( ( k >= 2 && ccw( ch[k-2].fi , ch[k-1].fi , v[i].fi ) == -1 ) || ( k >= 1 && ch[k-1].fi == v[i].fi ) ) k--;

  REP( i , k ){
    if( i > 0 && ch[i].fi.se <= ch[i-1].fi.se ) break;
    ss.insert( ch[i].fi );
  }
  REP( i , n ) if( ss.find( v[i].fi ) != ss.end() ) ans.pb( v[i].se );
  SORT( ans );
  REP( i , SZ(ans) ) printf( "%lld%c" , ans[i]+1 , i==SZ(ans)-1?'\n':' ' );
  
  return 0;
}