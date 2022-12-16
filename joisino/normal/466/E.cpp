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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct node{
  node *p, *chl, *chr;
  int key;
  node(){
    p = chl = chr = NULL;
  }

  bool is_root(){
    return !p || ( (p->chl) != this && (p->chr) != this );
  }

  void ror(){
    node *pp = p;
    node *r = pp->p;
    pp->chl = chr;
    if( chr ) chr->p = pp;
    chr = pp;
    pp->p = this;
    p = r;
    if( r ){
      if( r->chl == pp ) r->chl = this;
      if( r->chr == pp ) r->chr = this;
    }
  }

  void rol(){
    node *pp = p;
    node *r = pp->p;
    pp->chr = chl;
    if( chl ) chl->p = pp;
    chl = pp;
    pp->p = this;
    p = r;
    if( r ){
      if( r->chl == pp ) r->chl = this;
      if( r->chr == pp ) r->chr = this;
    }
  }

  node* splay(){
    while( !is_root() ){
      if( p->is_root() ){
	if( p->chl == this ) ror();
	else rol();
      } else {
	node *r = p->p;
	if( r->chl == p ){
	  if( p->chl == this ){
	    p->ror();
	    ror();
	  } else {
	    rol();
	    ror();
	  }
	} else {
	  if( p->chl == this ){
	    ror();
	    rol();
	  } else {
	    p->rol();
	    rol();
	  }
	}
      }
    }
    return this;
  }
};

node nodes[1000010];
int p;

node *root = NULL;

int key( node *x ){
  return x ? x->key : 0;
}

node* expose( node* t ){
  node *rp = NULL;
  for( node *c = t; c; c=c->p ){
    c->splay();
    c->chr = rp;
    rp = c;
  }
  t->splay();
  return t;
}

void cut( node *t ){
  expose( t );
  node *lp = t->chl;
  t->chl = NULL;
  lp->p = NULL;
}

void link( node *c , node *p ){
  expose( c );
  expose( p );
  c->p = p;
  p->chr = c;
}

node* access( node* t , int x ){
  if( !t || t->key == x ) return t?root=t->splay():t;
  if( x < t->key ) return access( t->chl , x );
  return access( t->chr , x );
}

node *merge( node *l , node *x , node *r ){
  x->chl = l;
  x->chr = r;
  x->p = NULL;
  if( l ) l->p = x;
  if( r ) r->p = x;
  return root = x;
}

// maximum node not more than x
node *le( node *t , int x ){
  if( !t ) return NULL;
  if( t->key == x ) return t;
  if( t->key > x ) return le( t->chl , x );

  node *res = le( t->chr , x );
  if( res ) return res;
  return t;
}

pair<node*,node*> split( node *t , int x ){ //(-INF,x] , (x,INF)
  node *res = le( t , x );
  if( !res ) return pair<node*,node*>( NULL , t );

  res->splay();
  node *r = res->chr;
  if( r ) r->p = NULL;
  res->chr = NULL;
  return make_pair( res , r );
}

node *insert( node *t , int x ){
  node *res = access( t , x );
  if( res ) return res;

  nodes[p].key = x;
  
  pair<node*, node*> P = split( t , x );

  return merge( P.first , &nodes[p++] , P.second );
}

node *erase( node *t , int x ){
  node *res = access( t , x );
  if( !res ) return t;

  if( res->chl ){
    if( !res->chr ){
      res->chl->p = NULL;
      return root = res->chl;
    }
    node *lm = le( res->chl , res->chr->key );
    pair<node*, node*> P = split( res->chl , lm->key-1 );
    return merge( P.first , P.second , res->chr );
  } else {
    res->chr->p = NULL;
    return root = res->chr;
  }
}

int lca( node *a , node *b ){
  if( a == b ) return a->key;
  expose(a);
  expose(b);
  if( !a->p ) return -1;
  int sametree = a->key;
  for( node *c = a; c; c = c->p ){
    if( c->p->chl != c && c->p->chr != c ) sametree = c->p->key;
    if( c->p == b ){
      return sametree;
    }
  }
}

const int MAX_N = 100010;

int n, m;
int t[MAX_N];
int x[MAX_N], y[MAX_N];

int nq;

bool ans[MAX_N];

typedef pair<pi,int> pii;

pii qs[MAX_N];

int main(){

  
  scanf( "%d %d" , &n , &m );

  REP( i , n ){
    nodes[i+1].key = i+1;
  }
  p = n+1;
  
  
  REP( i , m ){
    scanf( "%d" , &t[i] );
    if( t[i] == 1 ){
      scanf( "%d %d" , &x[i] , &y[i] );
    } else if( t[i] == 2 ){
      scanf( "%d" , &x[i] );
    } else if( t[i] == 3 ){
      scanf( "%d %d" , &qs[nq].fi.se , &qs[nq].fi.fi );
      qs[nq].se = nq;
      nq++;
    }
  }

  sort( qs , qs+nq );

  int cnt = 1;
  int pc = 0;
  REP( i , m ){
    if( t[i] == 1 ){
      link( &nodes[x[i]] , &nodes[y[i]] );
    } else if( t[i] == 2 ){
      while( pc < nq && qs[pc].fi.fi == cnt ){
	if( lca( &nodes[x[i]] , &nodes[qs[pc].fi.se] ) == qs[pc].fi.se ) ans[qs[pc].se] = true;
	pc++;
      }
      cnt++;
    } else if( t[i] == 3 ){
    }
  }

  REP( i , nq ){
    if( ans[i] ) puts( "YES" );
    else puts( "NO" );
  }

  
  return 0;
}