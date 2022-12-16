#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
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

char cs[MAX_N];

bool mas, fem;
int cnt;

bool ok = false;

int main(){

  int p = 0;
  while( scanf( "%s" , cs ) != EOF ){
    string s = cs;
    int n = s.length();
    if( n >= 4 && s.substr( n - 4 ) == "lios" ){
      mas = true;
      if( p > 0 ) return puts( "NO" );
    } else if( n >= 5 && s.substr( n - 5 ) == "liala" ){
      fem = true;
      if( p > 0 ) return puts( "NO" );
    } else if( n >= 3 && s.substr( n - 3 ) == "etr" ){
      mas = true;
      ok = true;
      if( p >= 1 ) return puts( "NO" );
      p = 1;
    } else if( n >= 4 && s.substr( n - 4 ) == "etra" ){
      fem = true;
      ok = true;
      if( p >= 1 ) return puts( "NO" );
      p = 1;
    } else if( n >= 6 && s.substr( n - 6 ) == "initis" ){
      mas = true;
      p = 2;
    } else if( n >= 6 && s.substr( n - 6 ) == "inites" ){
      fem = true;
      p = 2;
    } else {
      return puts( "NO" );
    }
    cnt++;
  }

  if( cnt == 1 ) return puts( "YES" );

  if( !ok ) return puts( "NO" );
  
  if( mas && fem ) return puts( "NO" );
  puts( "YES" );
  
  return 0;
}