#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

using namespace std;

typedef long long int ll;

const int INF = 1e9;
const double EPS = 1e-7;

template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

struct node{
  int add;
  int val;
  node *chl, *chr;
  node(){}
  node( int val , int add ) : val(val) , add(add){
    chl = chr = NULL;
  }
  node( int val , int add , node* chl , node* chr ) : val(val) , add(add) , chl(chl) , chr(chr){}
};

int size;
node nodes[10000000];
int np;
node* root;

int val( node* t ){ return !t ? 0 : t->val; }
node* chl( node* t ){ return !t ? NULL : t->chl; }
node* chr( node* t ){ return !t ? NULL : t->chr; }

node* newnode( int val = 0, int add = 0, node* chl = NULL, node* chr = NULL ){
  nodes[np] = node( val, add , chl, chr );
  return &nodes[np++];
}

void makech( node *t ){
  if( !t->chl ) t->chl = newnode();
  if( !t->chr ) t->chr = newnode();
}

node* init( int n ){
  size = 1;
  while( size < n ) size *= 2;
  return newnode();
}

void update( node* t , int a , int b , int x , int l , int r ){
  if( a <= l && r <= b ){
    chmax( t->val , x );
  } else if( b <= l || r <= a ) {
    return;
  } else {
    makech( t );
    update( chl(t) , a , b , x , l , (l+r)/2 );
    update( chr(t) , a , b , x , (l+r)/2 , r );
  }
}

int query( node* t , int a , int b, int l, int r ){
  if( !t )
    return 0;
  if( a <= l && r <= b )
    return t->val;
  else if( b <= l || r <= a )
    return 0;
  else
    return max( t->val , max( query( chl(t), a, b, l, (l+r)/2 ) , query( chr(t), a, b ,(l+r)/2, r ) ) );
}

set<int> vs, hs;

int main(){

  int n, q;
  cin >> n >> q;

  node *v = init( n+1 );
  node *h = init( n+1 );

  update( v , 0 , size , 0 , 0 , size );
  update( h , 0 , size , 0 , 0 , size );
  
  REP( i , q ){
    int x, y;
    cin >> x >> y;
    char t;
    cin >> t;

    if( t == 'L' ){
      if( hs.find( y ) == hs.end() ){
	int st = query( v , y , y+1 , 0 , size );
	cout << x - st << endl;
	update( h , st+1 , x+1 , y , 0 , size );
	hs.insert( y );
      } else {
	cout << 0 << endl;
      }
    } else if( t == 'U' ){
      if( vs.find( x ) == vs.end() ){
	int st = query( h , x , x+1 , 0 , size );
	cout << y - st << endl;
	update( v , st+1 , y+1 , x , 0 , size );
	vs.insert( x ); 
      } else {
	cout << 0 << endl;
      }
    }
  }
  
  return 0;
}