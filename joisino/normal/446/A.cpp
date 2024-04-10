#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


const int MAX_N = 100010;

int n;
int a[MAX_N], f[MAX_N], t[MAX_N];
int ans = 0;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );
  a[n] = INF+10;

  REP( i , n ) f[i] = i;
  FOR( i , 1 , n ) if( a[i-1] < a[i] ) f[i] = f[i-1];

  for( int i = n-1; i >= 0; i-- ){
    if( f[i] == 0 && i == n-1 ) chmax( ans , i - f[i] + 1 );
    else if( f[i] >= 2 && ( a[f[i]-2] < a[f[i]] - 1 || a[f[i]-1] < a[f[i]+1]-1 ) ) chmax( ans , i - f[f[i]-1] + 1 );
    else chmax( ans , i - f[i] + 2 );
  }

  printf( "%d\n" , ans );
  
  return 0;
}