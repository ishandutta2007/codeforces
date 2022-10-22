#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int MaxN = 500100;
const int half = 500001;
const int S = 1000000;

#define x first
#define y second
typedef pair<int, int> point;

int a[MaxN];
int p;
vector<int> ans;
int m[MaxN*2];
int taken[MaxN*2];
int bio[MaxN*2];
int n;

int main() {

  ios_base::sync_with_stdio(false);
  for( int i=1; i<half; i++ ) {
    m[i] = S - i + 1;
    m[S-i+1] = i;
  }
  cin >> n;
  for( int i=0; i<n; i++ ) {
    int x;
    cin >> x;
    a[i] = x;
    taken [ x ] = 1;
  }
  for( int i=0; i<n; i++ ) {
    if( taken[ a[i] ] and taken[ m[ a[i] ] ] and !bio[ a[i] ] ) {

      bio[ m[ a[i] ] ] = 1;
      p++;

    }else if( taken[ a[i] ] and !bio[ a[i] ] ) {

      ans.push_back( m[ a[i] ] );
      taken[ m[ a[i] ] ] = 1;
      bio[ m[ a[i] ] ] = 1;

    }
  }
  for( int i=1; p; i++ ) {
    if( !taken[i] and !taken[ m[i] ] ) {
      taken[i] = 1;
      taken[ m[i] ] = 1;
      ans.push_back( i );
      ans.push_back( m[i] );
      p--;
    }
  }
  //sort( ans.begin(), ans.end() );

  cout << ans.size() << endl;
  for( int i=0; i<ans.size(); i++ ) cout << ans[i] << " ";
  return 0;
}