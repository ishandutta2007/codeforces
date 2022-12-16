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

const int MAX_N = 2010;

int n;
int cnt;
double x;
int a[MAX_N*2];
int sum;

int main(){

  scanf( "%d" , &n );
  REP( i , n*2 ){
    scanf( "%lf" , &x );
    a[i] = x*1000+0.5;
    a[i] %= 1000;
    if( a[i] == 0 ) cnt++;
    sum += a[i];
  }

  ll res = 1000*n-sum;
  ll ans = INFLL;
  REP( i , min(n,cnt)+1 ) chmin( ans , abs( res - 1000*i ) );

  printf( "%d.%03d\n" , (int)(ans/1000) , (int)(ans%1000) );
  
  
  return 0;
}