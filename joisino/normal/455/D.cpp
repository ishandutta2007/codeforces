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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int B = 400;
const int MAX_N = 102010;

int n, q;
int a[MAX_N];

deque<int> b[MAX_N/B];
int c[MAX_N/B][MAX_N];

int lastans;

void rotate( int l , int r ){
  deque<int> res;
  res.clear();
  if( l/B == r/B ){
    REP( i , l%B ) res.push_back( b[l/B][i] );
    res.push_back( b[l/B][r%B] );
    FOR( i , l%B , r%B ) res.push_back( b[l/B][i] );
    FOR( i , r%B+1 , B ) res.push_back( b[l/B][i] );
    b[l/B] = res;
    return;
  }
  
  REP( i , l%B ) res.push_back( b[l/B][i] );
  res.push_back( b[r/B][r%B] );
  c[l/B][ b[r/B][r%B] ]++;
  FOR( i , l%B , B ) res.push_back( b[l/B][i] );
  b[l/B] = res;

  res.clear();
  REP( i , r%B ) res.push_back( b[r/B][i] );
  c[r/B][ b[r/B][r%B] ]--;
  FOR( i , r%B+1 , B ) res.push_back( b[r/B][i] );
  b[r/B] = res;

  FOR( i , l/B , r/B ){
    b[i+1].push_front( b[i].back() );
    c[i+1][ b[i].back() ]++;
    c[i  ][ b[i].back() ]--;
    b[i].pop_back();
  }
}

int query( int l , int r , int k ){
  int ans = 0;
  if( l/B == r/B ){
    FOR( i , l , r ) if( b[i/B][i%B] == k ) ans++;
    return ans;
  }

  FOR( i , l , (l/B+1)*B ) if( b[i/B][i%B] == k ) ans++;
  FOR( i , (r/B)*B , r ) if( b[i/B][i%B] == k ) ans++;
  FOR( i , l/B+1 , r/B ) ans += c[i][k];
  return ans;
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );
  FOR( i , n , ((n-1)/B+1)*B ) a[i] = n+1;
  int on = n;
  n = ((n-1)/B+1)*B;
  REP( i , n ) b[i/B].push_back( a[i] );
  REP( i , n ) c[i/B][ a[i] ]++;

  scanf( "%d" , &q );
  REP( query_cnt , q ){
    int t, l, r, k;
    scanf( "%d" , &t );
    if( t == 1 ){
      scanf( "%d %d" , &l , &r );
      l = ( l + lastans - 1 ) % on + 1;
      r = ( r + lastans - 1 ) % on + 1;
      if( l > r ) swap( l , r );
      rotate( l-1 , r-1 );
    } else if( t == 2 ){
      scanf( "%d %d %d" , &l , &r , &k );
      l = ( l + lastans - 1 ) % on + 1;
      r = ( r + lastans - 1 ) % on + 1;
      k = ( k + lastans - 1 ) % on + 1;
      if( l > r ) swap( l , r );
      lastans = query( l-1 , r , k );
      printf( "%d\n" , lastans );
    }
  }

  return 0;
}