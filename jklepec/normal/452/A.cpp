#include <iostream>
#include <vector>
using namespace std;

string s;
string a[8] = { "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon" };
vector <string> v;

int main() {
  int n;
  cin >> n;
  cin >> s;
  for( int i=0; i<8; i++ ) v.push_back( a[i] );

  while(v.size()-1) {
    string samp = v[ v.size()-1 ];
    if( samp.size() != n ) {
        v.pop_back();
    }else {
      bool moze = true;
      for( int i=0; i<n; i++ )
        if( s[i] != '.' and s[i] != samp[i] ) moze = false;
      if(moze){
        cout << samp ; return 0;
      }else v.pop_back();
    }

  }
  cout << v[0];
  return 0;
}