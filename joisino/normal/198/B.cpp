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

const int MAX_N = 100010;

int n, k;
char ca[MAX_N], cb[MAX_N];
string s[2];

typedef pair<int,pi> st;

priority_queue<st,vector<st>,greater<st> > que;

int dist[2][MAX_N];

bool ok = false;

int nt, nh, nd;

int main(){

  scanf( "%d %d" , &n , &k );
  scanf( "%s %s" , ca , cb ); s[0] = ca; s[1] = cb;

  REP( i , 2 ) REP( j , MAX_N ) dist[i][j] = INF;
  dist[0][0] = 0;
  
  que.push( st( 0 , pi( 0 , 0 ) ) );
  while( !que.empty() ){
    int t = que.top().se.fi;
    int h = que.top().se.se;
    int d = que.top().fi;
    que.pop();
    if( d > dist[t][h] ) continue;

    nt = t;
    nh = h + 1;
    nd = d + 1;
    if( nh >= nd && nh < n && s[nt][nh] == '-' && dist[nt][nh] > nd ){
      dist[nt][nh] = nd;
      que.push( st( nd , pi( nt , nh ) ) );
    }
    if( nh >= n ) ok = true;
    
    nt = t;
    nh = h - 1;
    if( nh >= nd && nh < n && s[nt][nh] == '-' && dist[nt][nh] > nd ){
      dist[nt][nh] = nd;
      que.push( st( nd , pi( nt , nh ) ) );
    }
    if( nh >= n ) ok = true;

    nt = 1 - t;
    nh = h + k;
    if( nh >= nd && nh < n && s[nt][nh] == '-' && dist[nt][nh] > nd ){
      dist[nt][nh] = nd;
      que.push( st( nd , pi( nt , nh ) ) );
    }
    if( nh >= n ) ok = true;

  }
  
  if( ok ) puts( "YES" );
  else puts( "NO" );
  
  
  return 0;
}