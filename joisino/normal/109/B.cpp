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
//typedef pair<ll,ll> pl;
typedef vector<int> vi;
//typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
//typedef vector<pl> vpl;
//typedef vector<vpl> gr;
typedef vector<vi> mi;
//typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

ll pl, pr, vl, vr, k;

vector<ll> lucky;

int main(){

  FOR( i , 1 , 10 ){
    REP( j , PW(i) ){
      ll res = 0;
      REP( k , i ) res = res * 10 + ((j&PW(k))?4:7);
      lucky.pb( res );
    }
  }
  int n = lucky.size();  
  lucky.pb( -INFLL );
  lucky.pb( INFLL );
  SORT( lucky );

  scanf( "%lld %lld %lld %lld %lld" , &pl , &pr , &vl , &vr , &k );

  ll cnt = 0;
  FOR( i , 1 , n-k+2 ){
    REP( j , 2 ){
      ll la = max( lucky[i-1] + 1 , pl );
      ll ra = min( lucky[i] , pr );
      
      ll lb = max( lucky[i+k-1] , vl );
      ll rb = min( lucky[i+k] - 1 , vr );

      if( la <= ra && lb <= rb ) cnt += ( ra - la + 1 ) * ( rb - lb + 1 );
      
      swap( pl , vl ); swap( pr , vr );
    }
    if( k == 1 && pl <= lucky[i] && lucky[i] <= pr && vl <= lucky[i] && lucky[i] <= vr ) cnt--;
  }
  
  printf( "%.18lf\n" , (double)cnt / (double)((pr-pl+1)*(vr-vl+1)) );
  
  return 0;
}