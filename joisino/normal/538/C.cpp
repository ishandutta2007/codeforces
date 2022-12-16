#include "bits/stdc++.h"

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long int ll;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }

const int MAX_M = 100010;

int d[MAX_M] , h[MAX_M];

int main(){

  int n , m;
  cin >> n >> m;

  REP( i , m )
    cin >> d[i] >> h[i];

  int ans = n-d[m-1]+h[m-1];
  chmax( ans , d[0]-1+h[0] );
  FOR( i , 1 , m ){
    int de = (d[i]-d[i-1])-abs(h[i]-h[i-1]);
    if( de < 0 ){
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }

    chmax( ans , max(h[i],h[i-1])+de/2 );
  }

  cout << ans << endl;
  
  return 0;
}