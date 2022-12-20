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

const int MAX_N = 100010;
const int MAX_P = 110;

int n, m, p;

int d[MAX_N];

ll a[MAX_N];

int s[MAX_P], t[MAX_P];
ll dp[MAX_P][MAX_N];
int st[MAX_P][MAX_N];

ll f( int k , int i , int x ){
  return a[i] * x + dp[k-1][i] - m * a[i];
}

bool check( int k , int f1 , int f2 , int f3 ){
  ll a1 = a[f1], b1 = dp[k-1][f1] - m * a[f1];
  ll a2 = a[f2], b2 = dp[k-1][f2] - m * a[f2];
  ll a3 = a[f3], b3 = dp[k-1][f3] - m * a[f3];
  return ( b3 - b1 ) * ( a1 - a2 ) <= ( b2 - b1 ) * ( a1 - a3 );
}

int main(){

  scanf( "%d %d %d" , &n , &m , &p );

  FOR( i , 1 , n ) scanf( "%d" , &d[i] );
  REP( i , n-1 ) d[i+1] += d[i];

  REP( i , m ){
    int h, t;
    scanf( "%d %d" , &h , &t ); h--;
    a[i] = t - d[h];
  }

  sort( a , a+m );
  reverse( a , a+m );

  ll sum = 0;
  REP( i , m ) sum += a[0] - a[i];

  REP( i , MAX_P ) REP( j , MAX_N ) dp[i][j] = INFLL;
  dp[0][0] = sum;

  t[0] = 1;
  
  FOR( i , 1 , m ) for( ll j = p-1; j >= 1; j-- ){
    while( t[j-1] - s[j-1] >= 2 && f( j , st[j-1][ s[j-1] ] , i ) >= f( j , st[j-1][ s[j-1]+1 ] , i ) ) s[j-1]++;

    dp[j][i] = f( j , st[j-1][ s[j-1] ] , i ) + ( m - i ) * a[i];
    
    while( t[j] - s[j] >= 2 && check( j+1 , st[j][ t[j]-2 ] , st[j][ t[j]-1 ] , i ) ) t[j]--;
    
    st[j][ t[j] ] = i; t[j]++;
  }

  ll ans = INFLL;
  REP( j , MAX_N ) chmin( ans , dp[p-1][j] );

  printf( "%lld\n" , ans );
  
  return 0;
}