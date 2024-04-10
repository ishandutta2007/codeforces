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

ll a[5][5];

ll ans;
vi v;

int main(){

  REP( i , 5 ) REP( j , 5 ) scanf( "%lld" , &a[i][j] );

  REP( i , 5 ) v.pb( i );

  do{
    ll res = a[v[0]][v[1]] + a[v[1]][v[0]];
    res += a[v[1]][v[2]] + a[v[2]][v[1]];
    res += ( a[v[2]][v[3]] + a[v[3]][v[2]] ) * 2;
    res += ( a[v[3]][v[4]] + a[v[4]][v[3]] ) * 2;    
    chmax( ans , res );
  } while( next_permutation( ALL(v) ) );

  printf( "%lld\n" , ans );
  
  return 0;
}