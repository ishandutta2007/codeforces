#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto x:arr)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }

const int MAX_N = 1000010;
const int B = 1000;
const int MAX_B = 1010;

typedef pair<P,int> PI;
vector<PI> ps;
int x, y;

int main(){

  int n = in();
  REP( i , n ){
    scanf( "%d %d" , &x , &y );
    if( (x/B) % 2 == 0 ) y *= -1;
    ps.pb( PI( P( x / B , y ) , i+1 ) );
  }

  sort( ALL(ps) );

  REP( i , n ){
    if( i != 0 ) printf( " " );
    printf( "%d" , int(ps[i].se) );
  }
  printf( "\n" );

  return 0;
}