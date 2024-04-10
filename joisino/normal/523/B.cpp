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


const ll MAX_N = 200010;

ll n, t, m;
double c;

ll q;

ll a[MAX_N];

ll sum;
double approx, re;

int main(){

  scanf( "%lld %lld %lf" , &n , &t , &c );
  REP( i , n ) scanf( "%lld" , &a[i] );
  scanf( "%lld" , &m );
  
  ll p = 0;
  REP( query_cnt , m ){
    scanf( "%lld" , &q );
    while( p < q ){
      sum += a[p];
      if( p >= t ) sum -= a[p-t];
      approx = ( approx + (double)a[p] / (double)t ) / (double)c;
      p++;
    }
    re = (double)sum / (double) t;
    printf( "%.18lf %.18lf %.18lf\n" , re , approx , abs( approx - re ) / re );
  }
  
  return 0;
}