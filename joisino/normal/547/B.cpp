#include "bits/stdc++.h"
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
 
const int INF = 1e9;
const double EPS = 1e-7;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int in(){ int a; cin >> a; return a; }

#define fi first
#define se second

struct Unionfind{
  vector<int> size;
  vector<int> par;

  Unionfind( int n ) :  size(n,1), par(n){
    iota( par.begin() , par.end() , 0 );
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


typedef pair<int,int> P;

int n;
vector<int> a;

vector<P> s;

bool used[200010];

vector<int> ans;

int main(){

  cin >> n;

  a.resize(n);
  REP( i , n )
    cin >> a[i];

  REP( i , n )
    s.pb( P( a[i] , i ) );
  sort( ALL(s) , greater<P>() );
  
  Unionfind uf(n);

  ans = vector<int>(n+1,-1);
  REP( i , n ){
    int h = s[i].fi;
    int p = s[i].se;

    used[p] = true;

    if( p > 0 && used[p-1] ) uf.unite( p , p-1 );
    if( p < n-1 && used[p+1] ) uf.unite( p , p+1 );

    int size = uf.size[ uf.find(p) ];
    
    if( ans[size] == -1 ) ans[size] = h;
  }

  FOR( i , 1 , n )
    chmax( ans[n-i] , ans[n-i+1] );
  
  REP( i , n ){
    if( i != 0 ) cout << " ";
    cout << ans[i+1];
  }
  cout << endl;
  
  return 0;
}