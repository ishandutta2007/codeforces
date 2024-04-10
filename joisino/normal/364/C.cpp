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

class Primes : public vi{
public:
  Primes( int max_n ){
    vb isp( max_n , true );
    FOR( i , 2 , max_n ){
      if( isp[i] ){
	pb( i );
	for( int j = i*2; j < max_n; j += i ) isp[j] = false;
      }
    }
  }
};

int k;

vi v;

Primes ps( 5010 );

int s = 0;
int cnt[5010];
bool test(){
  REP( i , s ) cnt[i] = 0;
  REP( i , k ) REP( j , s ) if( v[i] % ps[j] == 0 ) cnt[j]++;
  REP( j , s ) if( cnt[j] * 2 < k ) return false;
  return true;
}

int main(){

  scanf( "%d" , &k );
  int limit = k * k * 2;

  v.pb( 1 );
  YYS( w , ps ){
    int cur_size = v.size();
    if( cur_size >= k ) break;
    REP( i , cur_size ){
      int a = w;
      while( a * v[i] <= limit ){
	v.pb( a * v[i] );
	a *= w;
      }
    }
  }
  
  REVERSE( v );

  // if( !test() ) cout << "NG" << endl;
  
  REP( i , k ) printf( "%d%c" , v[i] , i==k-1?'\n':' ' );
  
  return 0;
}