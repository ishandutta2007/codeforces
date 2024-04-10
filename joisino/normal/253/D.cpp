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

const int MAX_N = 410;

int n, m, t;

char s[MAX_N][MAX_N];

int sum[MAX_N][MAX_N];

ll ans;
int cnt[26];

int main(){

  FILE *fp = fopen( "input.txt" , "r" );
  fscanf( fp , "%d %d %d" , &n , &m , &t );
  REP( i , n ) fscanf( fp , "%s" , s[i] );

  REP( i , n ) REP( j , m ) sum[i][j+1] = sum[i][j] + ( s[i][j] == 'a' ? 1 : 0 );

  REP( i , m ) FOR( j , i+1 , m ){
    REP( k , 26 ) cnt[i] = 0;
    int it = 0, res = 0;
    REP( k , n ){
      chmax( it , (int)k );
      while( it < n && res + ( sum[it][j+1] - sum[it][i] ) <= t ){
	if( s[it][i] == s[it][j] ) cnt[ s[it][i] - 'a' ]++;
	res += sum[it][j+1] - sum[it][i];
	it++;
      }
      if( it > k ){
	if( s[k][i] == s[k][j] ){
	  cnt[ s[k][i] - 'a' ]--;
	  ans += cnt[ s[k][i] - 'a' ];
	}
	res -= sum[k][j+1] - sum[k][i];
      }
    }
  }

  FILE *ofp = fopen( "output.txt" , "w" );
  fprintf( ofp , "%lld\n" , ans );
  
  return 0;
}