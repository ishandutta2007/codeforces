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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
template<class T> inline T sq( T a ){ return a * a; }
 
// head
int ans = 0;

pair<pi,pi> cut( pi a, int sz ){
  int c = PW(sz)-1;
  return make_pair( pi( min(c, a.fi), min(c, a.se) ), pi( max(0, a.fi-c-1), max(0, a.se-c-1) ) );
}

void rec( pi a, pi b, int sz ){
  // cout << a.fi << " " << a.se << " " << b.fi << " " << b.se << " " << sz << endl;
  chmax( ans, min(a.se,b.se) - max(a.fi,b.fi) );
  if( a.se-a.fi == 0 or b.se-b.fi == 0 ) return;
  if( a.se-a.fi == PW(sz)-1 or b.se-b.fi == PW(sz)-1 ) return;
  if( a.se > PW(sz-1)-1 ){
    auto res = cut( a, sz-1 );
    rec( res.fi, b, sz );
    rec( res.se, b, sz );
  } else if( b.se > PW(sz-1)-1 ){
    auto res = cut( b, sz-1 );
    rec( a, res.fi, sz );
    rec( a, res.se, sz );
  } else {
    rec( a, b, sz-1 );
  }
}

int main(){

  int a, b, c, d;
  scanf( "%d %d %d %d" , &a , &b , &c , &d ); a--; c--;

  rec( pi(a, b), pi(c, d), 30 );

  printf( "%d\n" , ans );
  
  return 0;
}