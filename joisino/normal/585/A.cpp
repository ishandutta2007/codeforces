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

int n;

vi ch;

int v[4010];
int d[4010];
int p[4010];

int main(){

  n = in();
  REP( i , n ){
    v[i] = in();
    d[i] = in();
    p[i] = in();
  }

  REP( i , n ){
    ch.pb( i );
  }

  vi ans(0);
  while( SZ(ch) > 0 ){
    int cur = ch[0];
    ch.erase( ch.begin() );
    // cout << cur << endl;
    ans.pb( cur );
    stack<int> st;
    while( !st.empty() ){
      st.pop();
    }
    REP( i , v[cur] ){
      if( i < SZ(ch) ){
        p[ ch[i] ] -= v[cur] - i;
        if( p[ ch[i] ] < 0 ){
          st.push( i );
        }
      }
    }
    while( !st.empty() ){
      int id = st.top();
      st.pop();
      int cry = ch[id];
      ch.erase( ch.begin() + id );
      int it = id;
      FOR( i , id , SZ(ch) ){
        p[ ch[i] ] -= d[cry];
        if( p[ ch[i] ] < 0 ){
          st.push( i );
        }
      }
    }
  }

  printf( "%lld\n" , SZ(ans) );
  REP( i , SZ(ans) ){
    if( i != 0 ){
      printf( " " );
    }
    printf( "%d" , ans[i]+1 );
  }
  printf( "\n" );

  return 0;
}