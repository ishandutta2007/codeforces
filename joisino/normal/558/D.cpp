#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int in(){ int a; cin >> a; return a; }

#define fi first
#define se second

vector<P> lv, rv;
int h , q;

int main(){

  cin >> h >> q;

  ll lb = 0, ub = ll(1)<<(h-1);

  REP( loop_cnt , q ){
    ll a , b , c , d;
    cin >> a >> b >> c >> d;

    b -= ll(1)<<(a-1);
    b <<= h-a;

    c -= ll(1)<<(a-1);
    c++;
    c <<= h-a;

    if( d == 1 ){
      chmax( lb , b );
      chmin( ub , c );
    } else {
      lv.pb( P( b , c ) );
      rv.pb( P( c , b ) );
    }
  }

  sort( ALL(lv) );
  sort( ALL(rv) , greater<P>() );

  REP( i , lv.size() )
    if( lv[i].fi <= lb && lb <  lv[i].se ) lb = lv[i].se;
  REP( i , rv.size() )
    if( rv[i].se <  ub && ub <= rv[i].fi ) ub = rv[i].se;

  if( lb >= ub ){
    cout << "Game cheated!" << endl;
  } else if( ub - lb == 1 ){
    cout << lb + (ll(1)<<(h-1)) << endl;
  } else {
    cout << "Data not sufficient!" << endl;
  }
  
  return 0;
}