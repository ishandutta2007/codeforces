#include "bits/stdc++.h"

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)

#define pb push_back

using namespace std;

typedef long long int ll;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }


int m , t , r;

int main(){

  scanf( "%d %d %d" , &m , &t , &r );

  if( t < r ){
    printf( "-1\n" );
    return 0;
  }

  priority_queue<int,vector<int>,greater<int> > que;
  int ans = 0;

  REP( cnt , m ){
    int a;
    cin >> a;
    while( !que.empty() && que.top() < a ) que.pop();

    int add = r - que.size();

    for( int i = 1; i <= add; i++ ){
      que.push( a-i+t );
      ans++;
    }
  }

  cout << ans << endl;
  
  return 0;
}