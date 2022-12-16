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

const int MAX_N = 100010;

int n, m, d;
int belong[MAX_N];
bool ng[PW(21)];

int cnt[21];

int main(){

  scanf( "%d %d %d" , &n , &m , &d );
  REP( i , m ){
    int size;
    scanf( "%d" , &size );
    REP( j , size ){
      int a;
      scanf( "%d" , &a ); a--;
      belong[a] = i;
    }
  }

  REP( i , n ){
    cnt[ belong[i] ]++;
    if( i >= d ) cnt[ belong[i-d] ]--;
    if( i >= d-1 ){
      int mask = 0;
      REP( i , m ) if( cnt[i] > 0 ) mask |= PW(i);
      ng[mask] = true;
    }
  }

  // mask : not taken
  int ans = m;
  REP( mask , PW(m) ){
    if( ng[mask] ){
      REP( i , m ) ng[mask|PW(i)] = true; // propagate
    } else {
      chmin( ans , m - __builtin_popcount( mask ) );
    }
  }

  printf( "%d\n" , ans );
  
  return 0;
}