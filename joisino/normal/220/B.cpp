#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define PW(x) (1LL<<(x))
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
const ll MOD = 1e9+9;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int n, m;
int a[MAX_N];

int c[MAX_N];
int p[MAX_N];
int cnt[600][MAX_N];

vi v;

int main(){

  
  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%d" , &a[i] );
  REP( i , n ) if( a[i] <= n ) c[ a[i] ]++;
  REP( i , n ) if( a[i] <= n && c[ a[i] ] >= a[i] ) v.pb( a[i] );
  SORT( v );
  v.erase( unique( ALL(v) ) , v.end() );
  int k = v.size();
  REP( i , MAX_N ) p[i] = -1;
  REP( i , v.size() ) p[ v[i] ] = i;
  REP( i , n ) if( a[i] <= n && p[ a[i] ] != -1 ) cnt[ p[ a[i] ] ][i+1] = 1;
  REP( i , k ) REP( j , n ) cnt[i][j+1] += cnt[i][j];
  REP( query_cnt , m ){
    int l, r;
    scanf( "%d %d" , &l , &r ); l--;
    int ans = 0;
    REP( i , k ) if( cnt[i][r] - cnt[i][l] == v[i] ) ans++;
    printf( "%d\n" , ans );
  }
  
  
  return 0;
}