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

const int MAX_N = 512;

int n, m;
int x[MAX_N];
int a, b, c;

double ans;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%d" , &x[i] );
  REP( i , m ){
    scanf( "%d %d %d" , &a , &b , &c ); a--; b--;
    chmax( ans , double( x[a] + x[b] ) / (double)c );
  }

  printf( "%.18lf\n" , ans );
  
  return 0;
}