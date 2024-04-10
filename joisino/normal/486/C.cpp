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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int n, p;
char s[MAX_N];

int minp = INF;
int maxp = -INF;

int main(){

  scanf( "%d %d" , &n , &p ); p--;
  scanf( "%s" , s );

  if( p >= n/2 ) p = n-1 - p;

  REP( i , (n+1)/2 ) if( s[i] != s[n-1-i] ){
    chmin( minp , i );
    chmax( maxp , i );
  }

  if( minp == INF ) return puts( "0" );

  ll ans = min( abs(p-maxp) , abs(p-minp) ) + abs(maxp-minp);
  REP( i , (n+1)/2 ) ans += min( abs(s[i]-s[n-1-i]) , 26 - abs(s[i]-s[n-1-i]) );

  printf( "%lld\n" , ans );
  
  return 0;
}