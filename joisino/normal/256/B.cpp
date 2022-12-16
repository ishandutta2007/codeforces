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

const int MAX_N = 100010;

ll n, x, y, c;

ll s( ll a ){
  return a * (a+1) / 2;
}

ll h( ll t , ll a ){
  if( t-a+1 <= 0 ) return 0;
  return s(t-a+1)+s(t-a);
}

ll r( ll t , ll a , ll b ){
  if( t-(a+b)+1 <= 0 ) return 0;
  return s(t-(a+b)+1);
}

bool check( ll t ){
  ll rx = n-x+1;
  ll ry = n-y+1;
  ll res = h(t,x) + h(t,y) + h(t,rx) + h(t,ry);
  res -= r(t,x,y) + r(t,rx,y) + r(t,x,ry) + r(t,rx,ry);
  res = (t+1)*(t+1) + t*t - res;
  return res >= c;
}

int main(){

  cin >> n >> x >> y >> c;
  
  ll lb = -1, ub = INF*2;
  while( ub - lb > 1 ){
    ll md = (lb+ub)/2;
    if( check( md ) ) ub = md;
    else lb = md;
  }

  cout << ub << endl;

  return 0;
}