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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const string ss[] = { "00" , "01" , "10" , "11" };

const ll MAX_N = 1024;

ll n, m;

char s[MAX_N][MAX_N][4];

ll cnt[4];

ll ans[MAX_N][MAX_N];

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , n ) REP( j , m ) scanf( "%s" , s[i][j] );

  REP( i , n ) REP( j , m ) REP( k , 4 ) if( string( s[i][j] ) == ss[k] ) cnt[k]++;

  cnt[1] += cnt[2];

  REP( i , n ) REP( j , m ) ans[i][j] = -1;
  REP( i , n ) REP( j , m ){
    if( ans[i][j] != -1 ) continue;
    if( cnt[3] > 0 ){
      ans[i][j] = 3;
      cnt[3]--;
    } else if( cnt[1] > 0 ){
      if( i < n-1 && cnt[1] >= 2 ){
	ans[i][j] = 1;
	ans[i+1][j] = 2;
	cnt[1] -= 2;
      } else {
	ans[i][j] = 1;
	cnt[1]--;
      }
    } else {
      ans[i][j] = 0;
    }
  }
  
  REP( i , n ) REP( j , m ) printf( "%s%c" , ss[ ans[i][j] ].c_str() , j==m-1?'\n':' ' );

  return 0;
}