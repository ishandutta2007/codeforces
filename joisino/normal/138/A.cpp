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

const int MAX_N = 10010;

int n, k;
char cs[MAX_N];
string t[4];

int ans = 0;

bool is_vowel( char c ){
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){

  scanf( "%d %d" , &n , &k );

  REP( i , n ){
    REP( j , 4 ){
      scanf( "%s" , cs );
      string s = cs;

      int p = s.size()-1;
      int cnt = 0;
      while( p >= 0 ){
	if( is_vowel( s[p] ) ) cnt++;
	if( cnt == k ) break;
	p--;
      }

      if( p == -1 ) return puts( "NO" );

      t[j] = s.substr( p );
    }

    if( t[0] == t[1] && t[1] == t[2] && t[2] == t[3] ) continue;

    if( t[0] == t[1] && t[2] == t[3] ){
      if( ans == 0 || ans == 1 ) ans = 1;
      else return puts( "NO" );
    } else if( t[0] == t[2] && t[1] == t[3] ){
      if( ans == 0 || ans == 2 ) ans = 2;
      else return puts( "NO" );
    } else if( t[0] == t[3] && t[1] == t[2] ){
      if( ans == 0 || ans == 3 ) ans = 3;
      else return puts( "NO" );
    } else return puts( "NO" );
  }

  if( ans == 0 ) puts( "aaaa" );
  else if( ans == 1 ) puts( "aabb" );
  else if( ans == 2 ) puts( "abab" );
  else if( ans == 3 ) puts( "abba" );
  
  return 0;
}