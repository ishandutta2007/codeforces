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

vector<int> fact( int x ){
  vector<int> res;
  for( int i = 2; i*i <= x; i++ ){
    if( x % i == 0 ){
      res.pb( i );
      while( x % i == 0 )
	x /= i;
    }
  }
  if( x != 1 ) res.pb( x );
  return res;
}

const int MAX_A = 500010;

multiset<int> G[MAX_A];
int cnt[MAX_A];
int a[MAX_A];
ll nt;

set<int> ss;

int main(){

  int n, q;
  cin >> n >> q;

  REP( i , n )
    cin >> a[i];

  int ans = 0;
 
  REP( qc , q ){
    int x = in()-1;
    vector<int> fs = fact( a[x] );

    if( ss.find( x ) == ss.end() ){
      FOR( i , 1 , 1<<fs.size() ){
	int v = 1;
	REP( j , fs.size() )
	  if( i & (1<<j) ) v *= fs[j];

	if( __builtin_popcount(i) % 2 == 1 ) nt += cnt[v];
	else nt -= cnt[v];

	cnt[v]++;
      }

      ss.insert( x );
    } else {
      FOR( i , 1 , 1<<fs.size() ){
	int v = 1;
	REP( j , fs.size() )
	  if( i & (1<<j) ) v *= fs[j];

	cnt[v]--;
	
	if( __builtin_popcount(i) % 2 == 1 ) nt -= cnt[v];
	else nt += cnt[v];
      }

      ss.erase( x );
    }

    
    cout << ll(ss.size())*ll(ss.size()-1)/2 - nt << endl;
  }
  
  return 0;
}