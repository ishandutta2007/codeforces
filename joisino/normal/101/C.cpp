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
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

ll ax, ay, bx, by, bxa, bya, bxb, byb;

bool check( ll arx , ll ary ){
  ll tx = bx - arx;
  ll ty = by - ary;
    
  if( bxa == 0 && bya == 0 ) return tx == 0 && ty == 0;

  ll dor = bxa * byb - bxb * bya;
  assert( dor != 0 );

  ll nx = byb * tx - bxb * ty;
  ll ny = - bya * tx + bxa * ty;

  return nx % dor == 0 && ny % dor == 0;
}

int main(){

  scanf( "%lld %lld" , &ax , &ay );
  scanf( "%lld %lld" , &bx , &by );
  scanf( "%lld %lld" , &bxa , &bya );
  
  bxb = -bya;
  byb = bxa;

  if( check( ax , ay ) || check( -ax , -ay ) || check( ay , -ax ) || check( -ay , ax ) ) puts( "YES" );
  else puts( "NO" );
  
  return 0;
}