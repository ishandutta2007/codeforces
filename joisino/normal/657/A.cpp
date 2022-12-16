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
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

int n, d, h;

int main(){

  n = in();
  d = in();
  h = in();

  if( d < h ){
    puts( "-1" );
  } else if( d == h ){
    if( d == 1 ){
      if( n == 2 ){
        puts( "1 2" );
      } else {
        puts( "-1" );
      }
    } else {
      if( n <= d ){
        puts( "-1" );
      } else {
        FOR( i , 1 , h+1 ){
          printf( "%lld %lld\n" , i, i+1 );
        }
        FOR( i , h+1 , n ){
          printf( "2 %lld\n", i+1 );
        }
      }
    }
  } else if( d > 2 * h ){
    puts( "-1" );
  } else if( n <= d ){
    puts( "-1" );
  } else {
    FOR( i , 1 , h+1 ){
      printf( "%lld %lld\n" , i , i+1 );
    }
    printf( "1 %d\n" , h+1+1 );
    FOR( i , 2 , d-h+1 ){
      printf( "%lld %lld\n" , h+i , h+i+1 );
    }
    FOR( i , d+1 , n ){
      printf( "1 %lld\n" , i+1 );
    }
  }

  return 0;
}