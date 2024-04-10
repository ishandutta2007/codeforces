#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long

ll row[1000][4];
ll a[1001][1001];

int sol;
int n;
int main() {


  scanf("%d", &n);
  for( int i=0; i<n; i++ ) for( int j=0; j<n; j++ ) scanf("%d", &a[i][j]);
  for( int i=0; i<n; i++ ) {
   sol+=a[i][i];
  }



  int q;
  scanf("%d", &q);

  for( int i=0; i<q; i++ ) {
    int x;
    scanf("%d", &x);
    if( x == 3 ) printf("%d", sol%2);
    else {
      ll y;
      scanf("%d", &y);
      y--;
      if( x == 1 ) {
        sol ++;
      }else {
        sol ++;
      }

    }
  }
  return 0;
}