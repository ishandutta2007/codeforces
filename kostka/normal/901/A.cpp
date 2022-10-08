//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())

int h;
vector <int> a;

void go(int w) {
  cout << "ambiguous\n";
  int ile = 0;
  for(int i=0; i<=h; i++) {
    for(int j=0; j<a[i]; j++) cout << ile << " ";
    ile += a[i];
  }
  cout << "\n";
  ile = 0;
  for(int i=0; i<=h; i++) {
    for(int j=0; j<a[i]; j++) cout << ((j==0 and i==w) ? ile-1 : ile) << " ";
    ile += a[i];
  }
  cout << "\n";
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> h;
  a.resize(h+1);
  for(int i=0; i<=h; i++) cin >> a[i];
  for(int i=1; i<=h; i++) if(min(a[i-1], a[i]) > 1) go(i);
  cout << "perfect\n";
  return 0;
}