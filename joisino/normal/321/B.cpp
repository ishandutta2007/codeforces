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

int n, m;
vi atk, def;
vi mine;

string s; int x;
int ans;

int main(){

  cin >> n >> m;
  REP( i , n ){
    cin >> s >> x;
    if( s[0] == 'A' ) atk.pb( x );
    else def.pb( x );
  }

  mine.resize( m );
  REP( i , m ) cin >> mine[i];


  SORT( atk );
  SORT( def );
  SORT( mine );

  FOR( i , 1 , atk.size()+1 ){
    bool ok = true;
    int res = 0;
    REP( j , i ){
      if( m-i+j >= 0 && mine[m-i+j] >= atk[j] ) res += mine[m-i+j] - atk[j];
      else ok = false;
    }
    if( ok ) chmax( ans , res );
  }

  int s = 0;
  REP( i , def.size() ){
    while( s < m && mine[s] <= def[i] ) s++;
    if( s < m ) mine[s] = -1;
  }
  
  if( s < m ){
    s = 0;
    int res = 0;
    REP( i , atk.size() ){
      while( s < m && mine[s] < atk[i] ) s++;
      if( s < m ){
	res += mine[s] - atk[i];
	mine[s] = -1;
      }
    }

    if( s < m ){
      REP( i , m ) if( mine[i] > 0 ) res += mine[i];
    }

    chmax( ans , res );
  }

  printf( "%d\n" , ans );
  
  
  return 0;
}