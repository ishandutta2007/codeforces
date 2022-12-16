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
const ll MOD = 2;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 128;

int k;
int n;

int G[MAX_N][MAX_N];


int main(){

  cin >> k;

  REP( i , MAX_N ){
    REP( j , i ){
      int cnt = 0;
      REP( k , i ) if( k != j ){
	if( G[i][k] && G[j][k] ) cnt++;
      }
      if( k - cnt >= 0 ){
	G[i][j] = G[j][i] = 1;
	k -= cnt;
      }
    }
    if( k == 0 ){
      n = i+1;
      break;
    }
  }
  
  printf( "%d\n" , n );
  REP( i , n ) REP( j , n ){
    printf( "%d" , G[i][j]  );
    if( j == n-1 ) printf( "\n" );
  }

  return 0;
}