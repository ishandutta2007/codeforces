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

const int MAX_N = 1000010;

int n;
int v[MAX_N];
int ma[MAX_N], mb[MAX_N];
int p[MAX_N];
int ans = 1;

int main(){

  REP( i , MAX_N ) ma[i] = mb[i] = -1;

  scanf( "%d" , &n );
  FOR( i , 1 , n+1 ){
    int a;
    scanf( "%d" , &a ); a--;
    p[i] = a;
    v[i] = 1;
    int c = i;
    while( a != 0 ){
      // cout << i << " " << c << " " << a << " " << v[c] << " " << ma[a] << " " << mb[a] << endl;
      if( ma[a] == -1 || v[ ma[a] ] < v[c] ){
	mb[a] = ma[a];
	ma[a] = c;
      } else if( ma[a] != c && ( mb[a] == -1 || v[ mb[a] ] < v[c] ) ){
	mb[a] = c;
      }
      int res = 1;
      if( ma[a] != -1 ) chmax( res , v[ ma[a] ] );
      if( mb[a] != -1 ) chmax( res , v[ mb[a] ] + 1 );
      if( v[a] == res ) break;
      v[a] = res;
      c = a;
      a = p[c];
    }
    
    if( a == 0 ) chmax( ans , v[c] );
    printf( "%d%c" , ans , i==n?'\n':' ' );
  }
  
  return 0;
}