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

const int MAX_N = 100010;

int n;
vec a;
vec d[MAX_N];
int eq;

int gd( int i , int k ){
  if( k < d[i].size() ) return d[i][k];
  return 0;
}

int geq(){
  REP( k , 30 )
    REP( i , n )
    if( gd(0,k) != gd(i,k) ) return k;
  return 30;
}

int so( int i ){
  FOR( k , eq , d[i].size() )
    if( d[i][k] == 1 ) return k;
  return d[i].size();
}

int main(){

  cin >> n;
  REP( i , n )
    a.pb( in() );

  REP( i , n ){
    while( a[i] > 0 )
      d[i].pb( a[i]%2 ), a[i] /= 2;
    reverse( d[i].begin() , d[i].end() );
  }

  eq = geq();

  int pr = 0;
  REP( i , n ){
    pr += d[i].size()-so(i);
    d[i].resize( so(i) );
  }

  int ans = INF;
  REP( k , 30 ){
    int res = pr;
    REP( i , n )
      res += abs( k - (int)d[i].size() );
    chmin( ans , res );
  }

  cout << ans << endl;
  
  return 0;
}