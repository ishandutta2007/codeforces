#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())

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
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int n;
pi a[MAX_N];
set<int> ss;

int ans[2][MAX_N];

map<int,int> ind;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i].fi );
  REP( i , n ) a[i].se = i;

  sort( a , a+n );

  int m = ( n + 2 ) / 3;

  REP( i , m ){
    ans[i%2][ a[i].se ] = 0;
    ans[1-i%2][ a[i].se ] = a[i].fi;
  }
  
  int c = 0;
  FOR( i , m , n ){
    ans[c%2][ a[i].se ] = a[i].fi - c / 2;
    ans[1-c%2][ a[i].se ] = c / 2;
    c++;
  }

  printf( "YES\n" );
  REP( j , 2 ) REP( i , n ) printf( "%d%c" , ans[j][i] , i == n-1 ? '\n' : ' ' );
  
  return 0;
}