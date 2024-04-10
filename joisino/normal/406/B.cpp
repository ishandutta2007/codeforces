#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;

const int INF = 1e9;
const ll INFLL = 1e18;
const ld EPS = 1e-8;
const ld EPSLD = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1000010;

int N = 1000000;
int n, a;
bool used[MAX_N];
int cnt;
vi ans;

int main(){

  scanf( "%d" , &n );
  REP( i , n ){
    scanf( "%d" , &a );
    used[a] = true;
  }

  REP( i , MAX_N ){
    if( used[i] ){
      if( used[N-i+1] ) cnt++;
      else ans.pb( N-i+1 );
    }
  }

  FOR( i , 1 , N+1 ){
    if( cnt == 0 ) break;
    if( !used[i] && !used[N-i+1] ){
      ans.pb( i );
      ans.pb( N-i+1 );
      cnt -= 2;
    }
  }

  printf( "%d\n" , (int)ans.size() );
  REP( i , ans.size() ){
    if( i != 0 ) printf( " " );
    printf( "%d" , ans[i] );
  }
  printf( "\n" );
  
  
  return 0;
}