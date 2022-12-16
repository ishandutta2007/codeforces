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
ll a[MAX_N][MAX_N];
ll p[MAX_N*2], q[MAX_N*2];

ll maxx[2] , maxy[2];

ll ge( ll x , ll y ){
  return p[x+y] + q[(n-1-x)+y] - a[x][y];
}

int main(){

  maxx[1] = 1;
  
  scanf( "%d" , &n );
  REP( i , n ) REP( j , n ){
    scanf( "%lld" , &a[i][j] );
    p[i+j] += a[i][j];
    q[(n-1-i)+j] += a[i][j];
  }

  /*
  REP( i , 2*n-1 ) cout << p[i] << endl;
  REP( i , 2*n-1 ) cout << q[i] << endl;
  */

  REP( i , n ) REP( j , n ){
    if( ge( maxx[(i+j)%2] , maxy[(i+j)%2] ) < ge( i , j ) ){
      maxx[(i+j)%2] = i;
      maxy[(i+j)%2] = j;
    }
  }

  cout << ge( maxx[0] , maxy[0] ) + ge( maxx[1] , maxy[1] ) << endl;
  cout << maxx[0]+1 << " " << maxy[0]+1 << " " << maxx[1]+1 << " " << maxy[1]+1 << endl;
  
  return 0;
}