#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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

struct ret{
  int v, l, r;
  ret( int v , int l , int r ) : v(v) , l(l) , r(r) {}
  ret(){}
};

struct node{
  int v, l, r;
  node *chl, *chr;
  node(){}
  node( int v , int l , int r ) : v(v), l(l) , r(r){
    chl = chr = NULL;
  }
  node( int v , int l , int r , node* chl , node* chr ) : v(v), l(l), r(r), chl(chl), chr(chr){}
};

int size;
node nodes[200010*24];
int np;
node *roots[200010];

int va( node* t ){ return !t ? 0 : t->v; }
int le( node* t ){ return !t ? 0 : t->l; }
int ri( node* t ){ return !t ? 0 : t->r; }
node *chl( node* t ){ return !t ? NULL : t->chl; }
node *chr( node* t ){ return !t ? NULL : t->chr; }

node *newnode( int v , int l , int r , node* chl = NULL , node* chr = NULL ){
  nodes[np] = node( v , l , r , chl , chr );
  return &nodes[np++];
}

node* init( int n ){
  size = 1;
  while( size < n ) size *= 2;
  return newnode( 0 , 0 , 0 );
}

node* update( node* t , int k , int l , int r ){
  if( r-l == 1 ){
    return newnode( 1 , 1 , 1 );
  } else {
    if( k < (l+r)/2 ){
      node *res = update( chl(t) , k , l , (l+r)/2 );
      int val = max( va(res) , va(chr(t)) );
      chmax( val , ri(res) + le(chr(t)) );
      int left  = le(res);
      if( left  == (r-l)/2 ) left  += le(chr(t));
      int right = ri(chr(t));
      if( right == (r-l)/2 ) right += ri(res);
      return newnode( val , left , right , res , chr(t) );
    } else {
      node *res = update( chr(t) , k , (l+r)/2 , r );
      int val = max( va(chl(t)) , va(res) );
      chmax( val , ri(chl(t)) + le(res) );
      int left  = le(chl(t));
      if( left  == (r-l)/2 ) left  += le(res);
      int right = ri(res);
      if( right == (r-l)/2 ) right += ri(chl(t));
      return newnode( val , left , right , chl(t) , res );
    }
  }
}

node* update( node* t , int k ){
  return update( t , k , 0 , size );
}

ret query( node* t , int a , int b , int l , int r ){
  if( !t ){
    return ret( 0 , 0 , 0 );
  } else if( a <= l && r <= b ){
    //cout << "* " << a << " " << b << " " << l << " " << r << " " << va(t) << " " << le(t) << " " << ri(t) << endl;
    return ret( va(t) , le(t) , ri(t) );
  } else if( b <= l || r <= a ){
    return ret( 0 , 0 , 0 );
  } else {
    ret cl = query( chl(t) , a , b , l , (l+r)/2 );
    ret cr = query( chr(t) , a , b , (l+r)/2 , r );
    int val = max( cl.v , cr.v );
    chmax( val , cl.r + cr.l );
    int left  = cl.l;
    if( left  == (r-l)/2 ) left  += cr.l;
    int right = cr.r;
    if( right == (r-l)/2 ) right += cl.r;
    return ret( val , left , right );
  }
}

ret query( node* t , int a , int b ){
  return query( t , a , b , 0 , size );
}

const int MAX_N = 100010;

int n, m;
pi h[MAX_N];

bool check( int l , int r , int w , int md ){
  //cout << md << " : " << endl;
  int v = query( roots[md] , l , r ).v;
  //cout << l << " " << r << " " << w << " " << md << " " << v << endl;
  return v >= w;
}
	   
int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &h[i].fi );
  REP( i , n ) h[i].se = i;
  sort( h , h+n );
  reverse( h , h+n );

  roots[0] = init( n );
  REP( i , n ) roots[i+1] = update( roots[i] , h[i].se );

  scanf( "%d" , &m );
  REP( query_cnt , m ){
    int l, r, w;
    scanf( "%d %d %d" , &l , &r , &w ); l--;
    int lb = 0, ub = n;
    while( ub - lb > 1 ){
      int md = ( lb + ub ) / 2;
      if( check( l , r , w , md ) ) ub = md;
      else lb = md;
    }
    printf( "%d\n" , h[ub-1].fi );
  }
  
  return 0;
}