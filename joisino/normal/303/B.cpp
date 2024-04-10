#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

ll n, m, x, y, aa, ab;
ll a, b;

typedef pair<pl,pl> pp;
typedef pair<pl,pp> ppp;

vector<ppp> v;

pp f( ll w, ll h ){
  ll x1 = x - (w+1)/2;
  ll y1 = y - (h+1)/2;
  chmax( x1 , 0LL );
  chmax( y1 , 0LL );
  ll x2 = x1 + w;
  ll y2 = y1 + h;
  if( x2 > n ){
    x1 -= x2 - n;
    x2 = n;
  }
  if( y2 > m ){
    y1 -= y2 - m;
    y2 = m;
  }
  return pp( pl( x1 , y1 ) , pl( x2 , y2 ) );
}

int main(){

  cin >> n >> m >> x >> y >> aa >> ab;
  a = aa / __gcd( aa , ab );
  b = ab / __gcd( aa , ab );

  ll k = min( n / a , m / b );
  a *= k; b *= k;

  
  pp w = f( a , b );
  
  cout << w.fi.fi << " " << w.fi.se << " " << w.se.fi << " " << w.se.se << endl;

  return 0;
}