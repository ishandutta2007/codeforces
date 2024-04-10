#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define PW(x) (1LL<<(x))
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

char s[MAX_N];

int cntz, cnto, cntq;

bool ans[4];

int main(){

  scanf( "%s" , s );
  int n = strlen( s );
  REP( i , n ){
    if( s[i] == '0' ) cntz++;
    if( s[i] == '1' ) cnto++;
    if( s[i] == '?' ) cntq++;    
  }

  if( cntz + cntq > cnto ) ans[0] = true;
  if( cntz < cnto + cntq - 1 ) ans[3] = true;

  if( cntz <= cnto + cntq && cntz + cntq >= cnto - 1 ){
    if( s[n-1] == '1' ) ans[1] = true;
    else if( s[n-1] == '0' ) ans[2] = true;
    else if( s[n-1] == '?' ){
      if( cntz <= cnto+1 + cntq-1 && cntz + cntq-1 >= cnto+1 - 1 ) ans[1] = true;
      if( cntz+1 <= cnto + cntq-1 && cntz+1 + cntq-1 >= cnto - 1 ) ans[2] = true;
    }
  }

  if( ans[0] ) puts( "00" );
  if( ans[1] ) puts( "01" );
  if( ans[2] ) puts( "10" );
  if( ans[3] ) puts( "11" );  
  
  
  return 0;
}