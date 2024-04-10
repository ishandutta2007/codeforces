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

const int MAX_N = 1010;

int n, k;

int size[MAX_N];
pi query[MAX_N];

pi table[MAX_N];

int ans_value;
vpi ans;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d %d" , &size[i] , &query[i].fi );
  REP( i , n ) query[i].se = i;

  sort( query , query + n );
  reverse( query , query + n );

  scanf( "%d" , &k );
  REP( i , k ) scanf( "%d" , &table[i].fi );
  REP( i , k ) table[i].se = i;

  sort( table , table + k );

  REP( i , n ){
    REP( j , k ) if( size[ query[i].se ] <= table[j].fi ){
      ans_value += query[i].fi;
      table[j].fi = -1;
      ans.pb( query[i].se , table[j].se );
      break;
    }
  }

  printf( "%d %d\n" , (int)ans.size() , ans_value );
  YYS( w , ans ) printf( "%d %d\n" , w.fi+1 , w.se+1 );
  
  return 0;
}