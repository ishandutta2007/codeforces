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

const ll MAX_N = 100010;

typedef pair<ll,pl> st;

ll n, m, k, p;
ll h[MAX_N], a[MAX_N];

priority_queue<st,vector<st>,greater<st> > que;

void push( st x ){
  if( x.fi >= m && x.se.fi - a[ x.se.se ] * m >= h[ x.se.se ] ) return;
  que.push( x );
}

bool check( ll g ){
  while( !que.empty() ) que.pop();
  REP( i , n ) push( st( g / a[i] , pl( g , i ) ) );

  REP( i , m ) REP( j , k ){
    if( que.empty() ) return true;
    
    st x = que.top(); que.pop();
    if( x.fi <= i ) return false;

    x.se.fi += p;
    x.fi = x.se.fi / a[ x.se.se ];
    
    push( x );
  }

  return que.empty();
}

int main(){

  scanf( "%lld %lld %lld %lld" , &n , &m , &k , &p );
  REP( i , n ) scanf( "%lld %lld" , &h[i] , &a[i] );

  ll lb = 0, ub = INFLL;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( check( md ) ) ub = md;
    else lb = md;
  }

  printf( "%lld\n" , ub );
  
  return 0;
}