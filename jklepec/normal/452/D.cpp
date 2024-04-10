#include <iostream>
#include <set>
using namespace std;

const int Max = 1010;

int k, s1, s2, s3, c1, c2, c3;
multiset<int> a1, a2, a3;
multiset<int>::iterator it;

int main() {

  int k;
  int sol;
  cin >> k;
  cin >> s1 >> s2 >> s3;
  cin >> c1 >> c2 >> c3;
  int MAX = max( max( c1, c2 ), c3 );

  for( int i=0; i<s1; i++ ) a1.insert( 0 );
  for( int i=0; i<s2; i++ ) a2.insert( 0 );
  for( int i=0; i<s3; i++ ) a3.insert( 0 );


  for( int i=0; i<k; i++ ) {
    int opt = max( *a3.begin(), max( *a1.begin(), *a2.begin() ) );

    it = a1.begin();

    a1.erase( it );
    a1.insert( opt + c1 );
    it = a2.begin();

    it = a2.begin();
    a2.erase( it );
    a2.insert( opt + c2 );
    it = a3.begin();

    it = a3.begin();
    a3.erase( it );
    a3.insert( opt + c3 );
    sol = opt + c1+c2+c3;
  }
  cout << sol;
  return 0;
}