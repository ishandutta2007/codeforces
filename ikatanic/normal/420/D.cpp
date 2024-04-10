#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> par;
#define a first
#define b second

const int MAXN = 2000100;

struct node {
  par x;
  int pri, size;
  node *l, *r;
  inline void update() { size = l->size + 1 + r->size; }
};

node mem[MAXN], *alloc = mem;

class Treap {
  node *root, *null;
public:
  Treap() {
    srand(12042992);
    null = alloc++;
    null->size = 0, null->pri = -1;
    null->l = null->r = null;
    root = null;
  };

  node *newnode( par x ) {
    node *p = alloc++;
    p->x = x, p->pri = rand();
    p->size = 1;
    p->l = p->r = null;
    return p;
  }

  node *rotate( node *x, node *y ) {
    if( x->l == y ) { x->l = y->r; y->r = x; } else
      if( x->r == y ) { x->r = y->l; y->l = x; }
    x->update(), y->update();
    return y;
  }

  node *insert( node *x, par z ) {
    if( x == null ) return x = newnode( z );
    if( z == x->x ) return x;
    if( z < x->x ) {
      x->l = insert( x->l, z );
      if( x->l->pri > x->pri ) x = rotate( x, x->l );
    } else {
      x->r = insert( x->r, z );
      if( x->r->pri > x->pri ) x = rotate( x, x->r );
    }
    x->update();
    return x;
  }

  node *erase( node *x, par z ) {
    if( x == null ) return null;
    if( z < x->x ) x->l = erase( x->l, z ); else
      if( z > x->x ) x->r = erase( x->r, z ); else {
	if( x->l == null && x->r == null ) return null;
	if( x->l->pri > x->r->pri ) x = rotate( x, x->l ); else
	  x = rotate( x, x->r );
	x = erase( x, z );
      }
    x->update();
    return x;
  }

  par kth( node *x, int k ) {
    if( k <= x->l->size ) return kth( x->l, k );
    if( k == x->l->size+1 ) return x->x;
    return kth( x->r, k - x->l->size - 1 );
  }

  par kth( int x ) { return kth( root, x ); }
  void erase( par x ) { root = erase( root, x ); }
  void insert( par x ) { root = insert( root, x ); }
  int size() { return root->size; }
} T;

int f[MAXN];
int g[MAXN];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  REP(i, n) {
    f[i] = g[i] = -1;
    T.insert({m+i, i});
  }

  par p;
  int x, y;
  REP(i, m) {
    scanf("%d %d", &x, &y); --x;
    // uzmi y-tog - on je jednak x, i ubaci na ga prvo mjesto
    if (T.size() < y) { puts("-1"); return 0; }
    p = T.kth(y);
    if (f[p.b] == -1) f[p.b] = x;
    if (g[x] == -1) g[x] = p.b;
    if (f[p.b] != x || g[x] != p.b) { puts("-1"); return 0; }
    
    T.erase(p);
    p.a = m-i-1;
    T.insert(p);
  }
  
  int ptr = 0;
  REP(i, n)
    if (g[i] == -1) {
      while (ptr < n && f[ptr] != -1) ptr++;
      if (ptr == n) { puts("-1"); return 0; } 
      f[ptr] = i;
    }

  REP(i, n)
    printf("%d%c", f[i]+1, i+1 < n ? ' ' : '\n');
  
  return 0;
}