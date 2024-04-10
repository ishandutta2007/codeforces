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
#define SHOW(x) cout << #x << " = " << x << endl
 
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
ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
// head

ll n, m;
vl G[5010];

ll s;
vpl store[5010];

ll q;

bool used[5010];

ll cn;
ll sum;

multiset<pl> ss;

vpl all;

void add( ll num , ll pri , ll b ){
  // cout << num << " " << pri << " " << b << endl;
  cn += num;
  sum += num * pri;

  ss.insert( pl( pri , num ) );
  all.pb( pri , num );

  while( cn > b ){
    auto ite = ss.end();
    assert( ite != ss.begin() );
    ite--;
    if( (*ite).se > cn - b ){
      pl ad = (*ite);
      ad.se -= cn - b;
      
      sum -= (*ite).fi * ( cn - b );
      cn = b;
      ss.erase( ite );
      
      ss.insert( ad );
    } else {
      sum -= (*ite).fi * (*ite).se;
      cn -= (*ite).se;
      ss.erase( ite );
    }
  }
}

bool check( ll b , ll c ){
  assert( cn <= b );
  return cn >= b and sum <= c;
}

bool naive_check( ll b , ll c ){
  SORT( all );
  YYS( w , all ){
    if( w.se >= b ){
      c -= w.fi * b;
      b = 0;
    } else {
      c -= w.fi * w.se;
      b -= w.se;
    }
  }
  return b == 0 and c >= 0;
}

ll solve( ll a , ll b , ll c ){
  vl cur = {};
  vl nex = { a };

  REP( i , n ){
    used[i] = false;
  }
  used[a] = true;
  
  ss.clear();
  cn = 0;
  sum = 0;

  all.clear();
  
  REP( i , n+1 ){
    cur = nex;
    
    YYS( w , cur ){
      YYS( u , store[w] ){
	add( u.fi , u.se , b );
      }
    }
    
    nex.clear();
    YYS( w , cur ){
      YYS( x , G[w] ){
	if( !used[x] ){
	  used[x] = true;
	  nex.pb( x );
	}
      }
    }

    /*
    if( check( b , c ) != naive_check( b , c ) ){
      cout << i << endl;
      YYS( w , all ){
	cout << w.fi << " " << w.se << endl;
      }
      cout << check( b , c ) << endl;
      cout << sum << endl;
      cout << cn << endl;
    }
    assert( check( b , c ) == naive_check( b , c ) );
    */
    
    if( check( b , c ) ){
      return i;
    }
  }

  return -1;
}

int main(){

  n = in();
  m = in();
  REP( i , m ){
    int a = in() - 1;
    int b = in() - 1;
    G[a].pb( b );
    G[b].pb( a );
  }

  s = in();
  REP( i , s ){
    int c = in() - 1;
    int a = in();
    int b = in();
    store[c].pb( a , b );
  }

  q = in();
  REP( qc , q ){
    int a = in() - 1;
    int b = in();
    int c = in();
    printf( "%lld\n" , solve( a , b , c ) );
  }
  
  return 0;
}