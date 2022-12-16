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

const int MAX_N = 256;

int n, m;
int le[MAX_N] , ri[MAX_N];

char s[MAX_N][MAX_N];

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%s" , s[i] );

  int last = 0;
  REP( i , n ){
    le[i] = INF;
    ri[i] = 0;
    REP( j , m ) if( s[i][j] == 'W' ){
      chmin( le[i] , j );
      chmax( ri[i] , j );
      last = i;
    }
  }

  int p = 0;
  int ans = 0;
  REP( i , n ){
    if( i % 2 == 0 ){
      int np = min( p , le[i] );
      ans += p - np;
      int nnp = max( np , ri[i] );
      ans += nnp - np;
      p = nnp;
    } else {
      int np = max( p , ri[i] );
      ans += np - p;
      int nnp = min( np , le[i] );
      ans += np - nnp;
      p = nnp;
    }
  }

  cout << ans + last << endl;
  
  return 0;
}