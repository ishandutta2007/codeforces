#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define PW(x) (1LL<<(x))
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


const int MAX_N = 72;

ll m;
int k;

ll C[MAX_N][MAX_N];

int a[MAX_N];

ll cnt( ll x ){
  REP( i , MAX_N ){
    a[i] = x % 2;
    x /= 2;
  }
  int c = 0;
  ll res = 0;
  for( int i = MAX_N-1; i >= 0; i-- ){
    if( a[i] == 1 && 0 <= k-c && k-c <= i ){
      res += C[i][k-c];
      c++;
    }
  }
  return res;
}

int main(){

  REP( i , MAX_N ){
    C[i][0] = C[i][i] = 1;
    FOR( j , 1 , i ) C[i][j] = C[i-1][j-1] + C[i-1][j];
  }

  
  
  cin >> m >> k;


  ll lb = 0, ub = INFLL;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( cnt( md * 2 + 1 ) - cnt( md + 1 ) >= m ) ub = md;
    else lb = md;
  }

  cout << ub << endl;
  
  return 0;
}