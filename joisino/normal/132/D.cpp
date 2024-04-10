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

const int MAX_N = 1000010;

char s[MAX_N];
int a[MAX_N];
int ans;

int main(){

  scanf( "%s" , s+1 );
  int n = strlen( s+1 ) + 1;
  s[0] = '0';  s[n] = '0';

  REP( i , n ){
    if( s[i] == '0' && s[i+1] == '1' ) a[i] = 1;
    if( s[i] == '1' && s[i+1] == '0' ) a[i] = -1;
  }
  REP( i , n ){
    if( a[i] == 1 && a[i+1] == -1 ) a[i] = 0, a[i+1] = 1;
    if( a[i] == -1 && a[i+1] == 1 ) a[i] = 0, a[i+1] = -1;
  }
  REP( i , n ) if( a[i] != 0 ) ans++;
  printf( "%d\n" , ans );
  REP( i , n ) if( a[i] != 0 ) printf( "%c2^%lld\n" , ( a[i] == 1 ? '+' : '-' ) , n-1-i );
  
  return 0;
}