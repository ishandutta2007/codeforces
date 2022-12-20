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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 256;

ll w, h;

char s[MAX_N][MAX_N];
string ans[MAX_N];

void sw(){
  REP( i , max(h,w) ) REP( j , i ) swap( s[i][j] , s[j][i] );
  swap( w , h );
}
void flip(){
  REP( i , h ) REP( j , w/2 ) swap( s[i][j] , s[i][w-1-j] );
}
void rot(){
  sw(); flip();
}

int main(){

  scanf( "%lld %lld" , &w , &h );
  REP( i , h ) scanf( "%s" , s[i] );

  rot();
  flip();

  REP( i , h ) REP( j , w ){
    ans[i*2  ] += string( 2 , s[i][j] );
    ans[i*2+1] += string( 2 , s[i][j] );
  }

  REP( i , h*2 ) printf( "%s\n" , ans[i].c_str() );
  
  return 0;
}