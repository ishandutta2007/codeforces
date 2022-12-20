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

const ll MAX_N = 100010;

ll n, k, w;
char s[MAX_N];

ll sum[12][MAX_N];
ll all;

int main(){

  scanf( "%lld %lld %lld" , &n , &k , &w );
  scanf( "%s" , s );

  REP( i , n ) sum[i%k][i/k+1] = sum[i%k][i/k] + ( s[i] - '0' );
  REP( i , n ) all += s[i] - '0';

  REP( i , w ){
    ll l, r;
    scanf( "%lld %lld" , &l , &r ); l--; r--;
    ll ans = 0;
    REP( j , k-1 ) ans += sum[(r-k+1+j)%k][(r-k+1+j)/k+1] - sum[(l+j)%k][(l+j)/k];
    ans += (r-l+1)/k - ( sum[r%k][r/k+1] - sum[(l+k-1)%k][(l+k-1)/k] );
    printf( "%lld\n" , ans );
  }
  
  return 0;
}