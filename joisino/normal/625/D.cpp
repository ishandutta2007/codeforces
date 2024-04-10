#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())

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
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-10;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<class T> inline T sq( T a ){ return a * a; }

// head

const int MAX_N = 100010;

int a[MAX_N];

string yuyu( int m , int p , int u , int d ){
  int ip = p;
  string res( m+1-2*p , 'x' );
  while( p < m-p ){
    int x = ( a[m-p] - u + 10 ) % 10;
    int s;
    if( a[p] == x ){
      s = x + d * 10;
      d = 0;
    } else if( ( a[p] + 9 ) % 10 == x ){
      if( a[p] == 0 ){
	if( d == 0 ) return "";
	else s = x;
      } else s = x + d * 10;
      d = 1;
    } else return "";
    if( s == 19 ) return "";
    res[p-ip] = '0' + ( s - s / 2 );
    res[m-p-ip] = '0' + ( s / 2 );
    u = ( s + u ) / 10;
    p++;
  }
  if( p == m-p ){
    int s = ( a[p] - u + 10 ) % 10 + d * 10;
    if( s % 2 == 0 ) res[p-ip] = '0' + ( s / 2 );
    else return "";
  } else if( u != d ) return "";
  if( res[0] == '0' ) return "";
  return res;
}

char s[MAX_N];
int n;

int main(){

  scanf( "%s" , s );
  n = strlen( s );
  REP( i , n ) a[i] = s[i] - '0';

  string res = yuyu( n-1 , 0 , 0 , 0 );
  if( res == "" && a[0] == 1 ) res = yuyu( n , 1 , 0 , 1 );

  if( res == "" ) puts( "0" );
  else printf( "%s\n" , res.c_str() );
  
  return 0;
}