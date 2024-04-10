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

struct node{
  ll sum;
  int cnt;
  node *chl, *chr;
  node(){}
  node( ll sum , int cnt ) : sum(sum) , cnt(cnt) {
    chl = chr = NULL;
  }
  node( ll sum , int cnt , node *chl , node *chr ) : sum(sum) , cnt(cnt) , chl(chl) , chr(chr) {}
};

const int MAX_N = 100010;

ll size;
node nodes[MAX_N * 80];
vector<node*> np;
node *root;

ll sum( node *t ){ return !t ? 0 : t->sum; }
int cnt( node *t ){ return !t ? 0 : t->cnt; }
node* chl( node* t ){ return !t ? NULL : t->chl; }
node* chr( node* t ){ return !t ? NULL : t->chr; }

node* newnode( ll sum = 0, int cnt = 0, node* chl = NULL, node* chr = NULL ){
  *np.back() = node( sum , cnt , chl, chr );
  node* ret = np.back();
  np.pop_back();
  return ret;
}

void makech( node *t ){
  if( !t->chl ) t->chl = newnode();
  if( !t->chr ) t->chr = newnode();
}

node* init( ll n ){
  size = 1;
  while( size < n ) size *= 2;
  return root = newnode();
}

void create( node *t , ll x , ll l , ll r ){
  if( r - l == 1 ){
    t->sum += x;
    t->cnt++;
  } else {
    if( x < (l+r)/2 ){
      if( !t->chl ) t-> chl = newnode();
      create( chl(t) , x , l , (l+r)/2 );
    } else {
      if( !t->chr ) t-> chr = newnode();      
      create( chr(t) , x , (l+r)/2 , r );
    }
    t->sum = sum(t->chl) + sum(t->chr);
    t->cnt = cnt(t->chl) + cnt(t->chr);
  }
}

void create( ll x ){
  create( root , x , 0 , size );
}

void del( node *t , ll x , ll l , ll r ){
  if( r - l == 1 ){
    t->sum -= x;
    t->cnt--;
    if( t->cnt == 0 ) np.pb( t );
  } else {
    if( x < (l+r)/2 ){
      del( chl(t) , x , l , (l+r)/2 );
      if( cnt(chl(t)) == 0 ) t->chl = NULL;
    } else {
      del( chr(t) , x , (l+r)/2 , r );
      if( cnt(chr(t)) == 0 ) t->chr = NULL;      
    }
    t->sum = sum(t->chl) + sum(t->chr);
    t->cnt = cnt(t->chl) + cnt(t->chr);
  }
}

void del( ll x ){
  del( root , x , 0 , size );
}

int ccc = 0;
double query( node *t , ll v , ll s , ll c , ll l , ll r ){
  if( !t || r - l == 1 ){
    ll nc = c + cnt(t);
    ll ns = s + sum(t);
    // cout << v << " " << s << " " << c << " " << ns << " " << nc << " " << l << " " << r << endl;
    return (double)( ns + v ) / (double)nc;
  } else {
    ll md = (l+r)/2;
    ll nc = c + cnt( t->chl );
    ll ns = s + sum( t->chl );
    if( md * nc - ns >= v ){
      return query( t->chl , v , s , c , l , md );
    } else {
      return query( t->chr , v , ns , nc , md , r );
    }
  }
}

double query( ll v ){
  return query( root , v , 0 , 0 , 0 , size );
}

int n, q;
ll a[MAX_N];

int main(){

  REP( i , MAX_N * 80 ) np.pb( &nodes[i] );
  
  scanf( "%d %d" , &n , &q );

  init( INF );
  
  REP( i , n ) scanf( "%lld" , &a[i] );
  REP( i , n ) create( a[i] );

  REP( query_cnt , q ){
    int t, p;
    ll x , v;
    scanf( "%d" , &t );
    if( t == 1 ){
      scanf( "%d %lld" , &p , &x ); p--;
      del( a[p] );
      a[p] = x;
      create( x );
    } else if( t == 2 ){
      scanf( "%lld" , &v );
      printf( "%.18lf\n" , query( v ) );
    }
  }

  return 0;
}