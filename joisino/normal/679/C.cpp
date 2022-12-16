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
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

   
const int dx[] = { 1 , 0 , -1 , 0 };
const int dy[] = { 0 , -1 , 0 , 1 };

struct Unionfind{
  vi size, par;
  Unionfind(){}
  Unionfind( int n ) :  size(n,1), par(n){
    REP( i , n ) par[i] = i;
  }
  void init( int n ){
    size = vi( n , 1 );
    par.resize( n );
    REP( i , n ) par[i] = i;
  }
  int find( int x ){
    if( par[x] == x ) return x;
    return par[x] = find( par[x] );
  }
  bool unite( int x , int y ){
    x = find(x);
    y = find(y);
    if( x == y ) return false;
    if( size[y] < size[x] ) swap( x , y );
    par[x] = y;
    size[y] += size[x];
    return true;
  }
  bool same( int x , int y ){
    return find(x) == find(y);
  }
};

Unionfind uf;

int n, k;

string s[512];

int cntin[512*512];
int cntout[512*512];

bool used[512*512];

vi ss;
vi ds;

bool isin( int y , int x ){
  return 0 <= y && y < n && 0 <= x && x < n;
}

int p( int y , int x ){
  return y * n + x;
}

void add( int y , int x ){
  if( s[y][x] == '.' ){
    int id = uf.find( p( y , x ) );
    cntout[id]++;
    if( cntout[id] == 1 ){
      ss.pb( id );
    }
  }
}

void del( int y , int x ){
  if( s[y][x] == '.' ){
    int id = uf.find( p( y , x ) );
    cntout[id]--;
    if( cntout[id] == 0 ){
      ds.pb( id );
    }
  }
}

int calc( int y , int x ){
  int res = k * k;
  YYS( w , ss ){
    res += uf.size[w];
    res -= cntin[w];
  }
  return res;
}

int main(){

  n = in();
  k = in();
  REP( i , n ){
    s[i] = stin();
  }

  uf.init( n * n );
  REP( i , n ){
    REP( j , n ){
      if( s[i][j] == '.' ){
        REP( k , 4 ){
          int ni = i + dy[k];
          int nj = j + dx[k];
          if( isin( ni , nj ) && s[ni][nj] == '.' ){
            uf.unite( p( i , j ) , p( ni , nj ) );
          }
        }
      }
    }
  }

  int ans = 0;
  REP( i , n ){
    if( i + k > n ){
      break;
    }
    REP( j , 512*512 ){
      cntin[j] = 0;
      cntout[j] = 0;
    }
    ss.clear();
    FOR( y , i , i+k ){
      REP( x , k ){
        if( s[y][x] == '.' ){
          cntin[ uf.find( p( y , x ) ) ]++;
        }
      }
    }
    if( i > 0 ){
      REP( x , k ){
        add( i-1 , x );
      }
    }
    if( i + k < n ){
      REP( x , k ){
        add( i+k , x );
      }
    }
    if( k < n ){
      FOR( y , i , i+k ){
        add( y , k );
      }
    }
    chmax( ans , calc( i , 0 ) );
    FOR( j , 1 , n ){
      if( j + k > n ){
        break;
      }
      if( i > 0 ){
        add( i-1 , j+k-1 );
      }
      if( i + k < n ){
        add( i+k , j+k-1 );
      }
      if( j + k < n ){
        FOR( y , i , i+k ){
          add( y , j+k );
        }
      }
      FOR( y , i , i+k ){
        add( y , j-1 );
      }

      ds.clear();
      if( i > 0 ){
        del( i-1 , j-1 );
      }
      if( i + k < n ){
        del( i+k , j-1 );
      }
      FOR( y , i , i+k ){
        del( y , j+k-1 );
      }
      if( j - 1 > 0 ){
        FOR( y , i , i+k ){
          del( y , j-2 );
        }
      }
      
      vi nss(0);
      YYS( w , ds ){
        used[w] = true;
      }
      YYS( w , ss ){
        if( !used[w] ){
          nss.pb( w );
        }
      }
      ss = nss;
      YYS( w , ds ){
        used[w] = false;
      }
      
      FOR( y , i , i+k ){
        if( s[y][j-1] == '.' ){
          cntin[ uf.find( p( y , j-1 ) ) ]--;
        }
        if( s[y][j+k-1] == '.' ){
          cntin[ uf.find( p( y , j+k-1 ) ) ]++;
        }
      }
      chmax( ans , calc( i , j ) );
    }
  }

  printf( "%d\n" , ans );
  
  return 0;
}