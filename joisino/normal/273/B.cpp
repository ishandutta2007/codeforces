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

map<ll,ll> cnt;

int n;
ll m;
ll a[MAX_N], b[MAX_N];

ll ans = 1;
ll coincide = 0;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );
  REP( i , n ) scanf( "%lld" , &b[i] );
  scanf( "%lld" , &m );

  REP( i , n ) cnt[ a[i] ]++;
  REP( i , n ) cnt[ b[i] ]++;
  
  REP( i , n ) if( a[i] == b[i] ) coincide++;

  YYS( w , cnt ){
    FOR( i , 1 , w.se+1 ){
      ll p = i;
      while( coincide > 0 && p % 2 == 0 ) p /= 2, coincide--;
      ans = ( ans * p ) % m;
    }
  }

  cout << ans << endl;
  
  return 0;
}