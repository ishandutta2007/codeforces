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

struct RBST{
  struct node{
    int val;
    int size;
    node *chl, *chr;
    node(){
      size = 1;
      chl = chr = NULL;
    }
    node( int val ) : val(val) {
      size = 1;
      chl = chr = NULL;
    }
  };

  typedef pair<node*,node*> pn;

  node nodes[10000000];
  int p;

  node *root;

  mt19937 mt;

  RBST(){
    root = NULL;
    mt.seed( time( NULL ) );
  };
  
  int size( node *t ){ return !t ? 0 : t->size; }
  int val ( node *t ){ return !t ? 0 : t->val;  }

  node* newnode( int val ){
    nodes[p] = node(val);
    return &nodes[p++];
  }

  node* update( node *t ){
    t->size = size( t->chl ) + size( t->chr ) + 1;
    return t;
  }

  node* merge( node *l , node *r ){
    if( !l ) return r;
    if( !r ) return l;

    if( (int)mt() % ( size(l) + size(r) ) < size(l) ){
      l->chr = merge( l->chr , r );
      return update( l );
    } else {
      r->chl = merge( l , r->chl );
      return update( r );
    }
  }

  pn split( node *t , int k ){ // [0,k) , [k,n)
    if( !t ) return pn( NULL , NULL );

    if( k <= size( t->chl ) ){
      pn s = split( t->chl , k );
      t->chl = s.se;
      return pn( s.fi , update( t ) );
    } else {
      pn s = split( t->chr , k - size(t->chl)-1 );
      t->chr = s.fi;
      return pn( update(t) , s.se );
    }
  }

  node* insert( node *t , int k , int val ){
    pn s = split( t , k );
    node* u = newnode( val );
    return merge( merge( s.fi , u ) , s.se );
  }

  void insert( int k , int val ){
    root = insert( root , k , val );
  }

  node* erase( node *t , int k ){
    pn sa = split( t , k );
    pn sb = split( sa.se , 1 );
    return merge( sa.fi , sb.se );
  }

  void erase( int k ){
    root = erase( root , k );
  }

  node* find( node *t , int k ){
    if( !t ) return NULL;
  
    if( k < size( t->chl ) ) return find( t->chl , k );
    else if( k == size( t->chl ) ) return t;
    else return find( t->chr , k - size(t->chl) - 1 );
  }

  node* find( int k ){
    return find( root , k );
  }

  int size(){
    return size( root );
  }
};

RBST rbst;

const ll MAX_N = 1000010;

ll n, m;

ll a[MAX_N];

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , m ) scanf( "%lld" , &a[i] ), a[i]--;

  REP( i , n ){
    ll x;
    scanf( "%lld" , &x );
    if( x == -1 ){
      REP( i , m ){
	if( SZ(rbst) > a[i]-i ) rbst.erase( a[i]-i );
	else break;
      }
    } else {
      rbst.insert( SZ(rbst) , x );
    }
  }

  if( SZ(rbst) == 0 ) printf( "Poor stack!" );
  else REP( i , SZ(rbst) ) printf( "%d" , rbst.val( rbst.find( i ) ) );
  printf( "\n" );
  
  return 0;
}