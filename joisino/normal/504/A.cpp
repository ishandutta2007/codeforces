#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

const int MAX_N = 100010;

int n;
int deg[MAX_N];
int s[MAX_N];

int from[MAX_N];
int to[MAX_N];

int main(){

  scanf( "%d" , &n );

  queue<int> que;
  for( int i = 0; i < n; i++ ){
    scanf( "%d %d" , &deg[i] , &s[i] );
    if( deg[i] == 1 ) que.push( i );
  }

  int cnt = 0;
  while( !que.empty() ){
    int x = que.front();
    que.pop();

    if( deg[x] == 1 ){
      from[cnt] = x;
      to[cnt] = s[x];
      cnt++;

      deg[x]--;
      deg[s[x]]--;
      s[s[x]] ^= x;

      if( deg[s[x]] == 1 ) que.push( s[x] );
    }
  }

  printf( "%d" , cnt );
  for( int i = 0; i < cnt; i++ )
    printf( "\n%d %d" , from[i] , to[i] );

  return 0;
}