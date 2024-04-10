#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

using namespace std;

typedef long long int ll;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int in(){ int a; cin >> a; return a; }

#define fi first
#define se second

typedef pair<int,int> P;
typedef vector<ll> vec;


const int MAX_N = 200010;

ll a[MAX_N];
int n;
ll k , x;

int size;
ll seg[MAX_N*4];

void init( int na ){
  size = 1;
  while( size < na ) size *= 2;
  REP( i , size*2-1 )
    seg[i] = 0;
}
void update( int k , ll x ){
  k += size-1;
  seg[k] = x;
  while( k > 0 ){
    k = (k-1)/2;
    seg[k] = seg[k*2+1] | seg[k*2+2];
  }
}

int main(){

  cin >> n >> k >> x;
  REP( i , n )
    cin >> a[i];

  ll t = 1;
  REP( i , k )
    t *= x;
  
  init( n );
  REP( i , n )
    update( i , a[i] );

  ll ans = 0;
  REP( i , n ){
    update( i , a[i]*t );
    chmax( ans , seg[0] );
    update( i , a[i] );
  }

  cout << ans << endl;
  
  return 0;
}