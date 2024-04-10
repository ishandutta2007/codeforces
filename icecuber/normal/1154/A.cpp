#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x,y,z,w;
  cin >> x >> y >> z >> w;
  long long ma = (x+y+z+w)/3;
  for (int i : {x,y,z,w}) {
    if (i < ma) cout << ma-i << ' ';
  }
}