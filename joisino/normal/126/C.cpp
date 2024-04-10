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

const int MAX_N = 2010;

int n;
char s[MAX_N][MAX_N];
int x[MAX_N][MAX_N];
int a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N];

int ans;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%s" , s[i] );
  REP( i , n ) REP( j , n ) x[i][j] = s[i][j] - '0';

  REP( i , n ) for( int j = n-1; j > i; j-- ){
    if( ( a[i] + b[j] + x[i][j] ) % 2 == 1 ){
      a[i]++; b[j]++; ans++;
    }
  }

  for( int i = n-1; i >= 0; i-- ) REP( j , i ){
      if( ( c[i] + d[j] + x[i][j] ) % 2 == 1 ){
	c[i]++; d[j]++; ans++;
      }
    }

  REP( i , n ) if( ( a[i] + b[i] + c[i] + d[i] + x[i][i] ) % 2 == 1 ) ans++;

  printf( "%d\n" , ans );
  
  return 0;
}