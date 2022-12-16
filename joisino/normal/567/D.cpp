#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }



int n , k , a, q;

int sts( int x ){
  if( x < a ) return 0;
  x -= a;
  return 1 + x / (a+1);
}

set<int> ss, ssb;

void insert( int x ){
  ss.insert( x );
  ssb.insert( -x );
}

int ns( int x ){
  return *ss.lower_bound( x );
}

int ps( int x ){
  return - *ssb.lower_bound( -x );
}


int main(){

  cin >> n >> k >> a;

  int res = sts( n );

  insert( 0 );
  insert( n+1 );
  
  cin >> q;
  REP( loop_cnt , q ){
    int x = in();
    int nx = ns( x );
    int px = ps( x );
    res -= sts( nx - px -1 );
    res += sts( nx - x - 1 );
    res += sts( x - px - 1 );
    insert( x );
    if( res < k ){
      cout << loop_cnt + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  
  return 0;
}