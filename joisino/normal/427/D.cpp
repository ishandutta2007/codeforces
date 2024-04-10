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
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct SA : public vi{
  int n, k;
  vi rank, tmp;
  
  bool compare( int i , int j ){
    if( rank[i] != rank[j] ) return rank[i] < rank[j];

    int ri = i + k <= n ? rank[i+k] : -1;
    int rj = j + k <= n ? rank[j+k] : -1;
    return ri < rj;
  }

  struct Compare_SA{
    SA *sa;
    Compare_SA( SA *s ) : sa(s) {}
    bool operator() ( const int &i , const int &j ){
      return sa->compare( i , j );
    }
  };

  void init( string S ){
    n = S.length();

    resize( n+1 );
    rank = tmp = vi( n+1 );
    REP( i , n+1 ){
      at(i) = i;
      rank[i] = i < n ? S[i] : -1;
    }

    for( k = 1; k <= n; k *= 2 ){
      sort( begin() , end() , Compare_SA(this) );

      tmp[at(0)] = 0;
      FOR( i , 1 , n+1 )
	tmp[at(i)] = tmp[at(i-1)] + (compare(at(i-1),at(i))?1:0);

      REP( i , n+1 ) rank[i] = tmp[i];
    }
  }
};


struct LCP : public vi{
  void init( string S , const SA &sa ){
    int n = S.length();

    vi rank(n+1);
    REP( i , n+1 ) rank[sa[i]] = i;

    int h = 0;
    resize( n , 0 );
    REP( i , n ){
      int j = sa[rank[i]-1];

      if( h > 0 ) h--;
      for( ; j+h < n && i+h < n; h++ ) if( S[j+h] != S[i+h] ) break;

      at(rank[i]-1) = h;
    }
  }
};

SA sa;
LCP lcp;

int ans = INF;

string s, t;

int main(){

  cin >> s >> t;
  int n = s.length();
  s = s + "#" + t;
  int m = s.length();
  sa.init( s );
  lcp.init( s , sa );

  REP( i , m ){
    if( ( sa[i] < n && sa[i+1] > n ) || ( sa[i] > n && sa[i+1] < n ) ){
      int l = 0;
      if( i > 0 ) chmax( l , lcp[i-1] );
      if( i < m-1 ) chmax( l , lcp[i+1] );
      if( lcp[i] > l ) chmin( ans , l+1 );
    }
  }

  if( ans == INF ) printf( "-1\n" );
  else printf( "%d\n" , ans );
  
  return 0;
}