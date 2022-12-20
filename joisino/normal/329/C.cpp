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

bool cmp( const vi &a , const vi &b ){
  return SZ(a) > SZ(b);
}

vi G[100010];

int n, m;

set<pi> es;

mi v;

vi cur;
bool used[100010];
void dfs( int x ){
  cur.pb( x );
  used[x] = true;
  YYS( w , G[x] ){
    if( not used[w] ){
      dfs( w );
    }
  }
}

int main(){

  n = in();
  m = in();
  REP( i , m ){
    int a = in() - 1;
    int b = in() - 1;
    es.insert( pi( a , b ) );
    es.insert( pi( b , a ) );
    G[a].pb( b );
    G[b].pb( a );
  }

  if( n <= 7 ){
    REP( mask , PW( n * (n-1) / 2 ) ){
      if( __builtin_popcount(mask) != m ){
        continue;
      }
      int cnt = 0;
      bool ok = true;
      vi deg( n , 0 );
      REP( i , n ){
        REP( j , i ){
          if( mask & PW(cnt) ){
            deg[i]++;
            deg[j]++;
            if( es.find( pi( i , j ) ) != es.end() ){
              ok = false;
            }
          }
          cnt++;
        }
      }
      REP( i , n ){
        if( deg[i] > 2 ){
          ok = false;
        }
      }
      if( ok ){
        cnt = 0;
        REP( i , n ){
          REP( j , i ){
            if( mask & PW(cnt) ){
              cout << i+1 << " " << j+1 << endl;
            }
            cnt++;
          }
        }
        return 0;
      }
    }
    cout << "-1" << endl;
    return 0;
  }
  
  REP( i , n ){
    if( not used[i] ){
      cur.clear();
      dfs( i );
      v.pb( cur );
    }
  }
  
  sort( ALL(v) , cmp );

  vi ma(0);
  for( int i = 0; i < SZ(v[0]); i += 2 ){
    ma.pb( v[0][i] );
  }
  for( int i = 1; i < SZ(v[0]); i += 2 ){
    ma.pb( v[0][i] );
  }

  if( SZ(ma) >= 2 ){
    swap( ma[0] , ma[1] );
  }
  
  cur.clear();
  FOR( i , 1 , SZ(v) ){
    REP( j , SZ(v[i]) ){
      cur.pb( v[i][j] );
    }
  }

  vi ans(0);
  REP( i , SZ(ma) ){
    for( int j = i; j < SZ(cur); j += SZ(ma) ){
      ans.pb( cur[j] );
    }
    ans.pb( ma[i] );
  }

  REP( i , m ){
    assert( es.find( pi( ans[i] , ans[(i+1)%SZ(ans)] ) ) == es.end() );
    printf( "%d %d\n" , ans[i]+1 , ans[(i+1)%SZ(ans)]+1 );
  }

  return 0;
}