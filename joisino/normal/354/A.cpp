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

int n, l, r, ql, qr;
ll a[MAX_N];
ll sum[MAX_N];

ll ans = INFLL;

int main(){

  scanf( "%d %d %d %d %d" , &n , &l , &r , &ql , &qr );
  REP( i , n ) scanf( "%lld" , &a[i] );

  REP( i , n ) sum[i+1] = sum[i] + a[i];
  REP( i , n+1 ) chmin( ans , sum[i]*l + (sum[n]-sum[i])*r + max(0,i-(n-i)-1)*ql + max(0,(n-i)-i-1)*qr );
  printf( "%lld\n" , ans );
  
  return 0;
}