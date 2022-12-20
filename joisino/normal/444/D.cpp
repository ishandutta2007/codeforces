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

int hs( string s ){
  int res = 0;
  YYS( w , s ) res = res * 27 + ( w - 'a' + 1 );
  return res;
}

const int B = 1000;
const int MAX_N = 60010;
const int MAX_H = 600010;

int qn;

char cs[MAX_N];
string s;

char ca[MAX_N], cb[MAX_N];
string sa, sb;

vi pos[MAX_H];
int len[MAX_H];
vi la;
mi lans;

int main(){

  scanf( "%s" , cs ); s = cs;
  int n = s.length();
  
  REP( i , n ) FOR( j , 1 , 5 ) if( i+j <= n ){
    int has = hs( s.substr( i , j ) );
    pos[has].pb( i );
    len[has] = j;
  }

  REP( i , MAX_H ) if( pos[i].size() >= B ){
    la.pb( i );
    vi res( MAX_H , INF );
    
    int p = 0;
    REP( j , n ){
      FOR( k , 1 , 5 ) if( j+k <= n ){
	int has = hs( s.substr( j , k ) );
	if( p < pos[i].size() ) chmin( res[has] , max( j + k , pos[i][p] + len[i] ) - j );
	if( p > 0 ) chmin( res[has] , max( j + k , pos[i][p-1] + len[i] ) - pos[i][p-1] );
      }
      if( p < pos[i].size() && pos[i][p] == j ) p++;
    }

    lans.pb( res );
  }

  scanf( "%d" , &qn );
  REP( query_cnt , qn ){
    scanf( "%s %s" , ca , cb ); sa = ca; sb = cb;
    int a = hs( sa );
    int b = hs( sb );

    int ans = INF;
    if( pos[a].size() >= B ){
      ans = lans[ lower_bound( ALL(la) , a ) - la.begin() ][b];
    } else if( pos[b].size() >= B ){
      ans = lans[ lower_bound( ALL(la) , b ) - la.begin() ][a];
    } else {
      int p = 0;
      YYS( w , pos[b] ){
	while( p < pos[a].size() && pos[a][p] < w ) p++;
	if( p < pos[a].size() ) chmin( ans , max( w + len[b] , pos[a][p] + len[a] ) - w );
	if( p > 0 ) chmin( ans , max( w + len[b] , pos[a][p-1] + len[a] ) - pos[a][p-1] );
      }
    }
    
    if( ans == INF ) ans = -1;
    printf( "%d\n" , ans );
  }
  
  return 0;
}