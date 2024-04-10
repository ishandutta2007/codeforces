#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
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
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 200010;

int n, m, k;
char s[MAX_N];

char qs[MAX_N];

int cnt[256][256];
int ans;

set<int> trans;

char get( int x ){ return s[ *trans.lower_bound( x ) ]; }

int main(){

  scanf( "%d %d %d" , &n , &m , &k );
  scanf( "%s" , s );
  REP( i , n ) if( s[i] != s[i+1] ){
    cnt[s[i]][s[i+1]]++;
    trans.insert( i );
  }
  s[n] = '#';
  trans.insert( n );

  REP( i , m ){
    int t, a, b;
    char c;
    scanf( "%d" , &t );
    if( t == 1 ){
      scanf( "%d %d %c" , &a , &b , &c ); a--; b--;
      char p = get(a-1);
      auto ite = trans.lower_bound( a-1 );
      while( *ite <= b ){
	cnt[get(*ite)][get((*ite)+1)]--;
	ite = trans.erase( ite );
      }
      if( a > 0 ){
	trans.insert( a-1 );
	s[a-1] = p;
      }
      trans.insert( b );
      s[b] = c;
      cnt[get(a-1)][get(a)]++;
      cnt[get(b)][get(b+1)]++;
    } else if( t == 2 ){
      scanf( "%s" , qs );
      ans = n;
      REP( i , k ) FOR( j , i+1 , k ) ans -= cnt[qs[i]][qs[j]];
      printf( "%d\n" , ans );
    }
  }
  
  
  return 0;
}