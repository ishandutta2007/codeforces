#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
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

vl fact( ll x ){
  vl res;
  for( ll i = 2; i <= 3; i++ ){
    while( x % i == 0 ){
      res.pb( i );
      x /= i;
    }
  }
  if( x > 1 ) res.pb( x );
  return res;
}

vpl facts( ll x ){
  vpl res;
  vl ps = fact( x );
  REP( i , ps.size() ){
    if( i == 0 || ps[i-1] != ps[i] ) res.pb( pl( ps[i] , 1 ) );
    else res.back().se++;
  }
  return res;
}

ll a[2], b[2];

int cnt[72];

vl f[2];

int ans;

int main(){

  REP( i , 2 ) cin >> a[i] >> b[i];

  REP( i , 2 ){
    f[i] = fact( a[i] * b[i] );
    reverse( ALL(f[i]) );
    while( !f[i].empty() && ( f[i].back() == 2 || f[i].back() == 3 ) ){
      if( i == 0 ) cnt[ f[i].back() ]++;
      else cnt[ f[i].back() ]--;
      f[i].pop_back();
    }
  }

  if( f[0] != f[1] ) return puts( "-1" );
  
  while( a[0] % 3 == 0 && cnt[3] > 0 ){
    a[0] /= 3; a[0] *= 2;
    cnt[3]--;
    cnt[2]++;
    ans++;
  }
  while( b[0] % 3 == 0 && cnt[3] > 0 ){
    b[0] /= 3; b[0] *= 2;
    cnt[3]--;
    cnt[2]++;    
    ans++;
  }
  while( a[1] % 3 == 0 && cnt[3] < 0 ){
    a[1] /= 3; a[1] *= 2;
    cnt[3]++;
    cnt[2]--;    
    ans++;
  }
  while( b[1] % 3 == 0 && cnt[3] < 0 ){
    b[1] /= 3; b[1] *= 2;
    cnt[3]++;
    cnt[2]--;
    ans++;
  }
  

  
  while( a[0] % 2 == 0 && cnt[2] > 0 ){
    a[0] /= 2;
    cnt[2]--;
    ans++;
  }
  while( b[0] % 2 == 0 && cnt[2] > 0 ){
    b[0] /= 2;
    cnt[2]--;
    ans++;
  }
  while( a[1] % 2 == 0 && cnt[2] < 0 ){
    a[1] /= 2;
    cnt[2]++;
    ans++;
  }
  while( b[1] % 2 == 0 && cnt[2] < 0 ){
    b[1] /= 2;
    cnt[2]++;
    ans++;
  }
  

  printf( "%d\n" , ans );
  REP( i , 2 ) printf( "%lld %lld\n" , a[i] , b[i] );
  

  return 0;
}