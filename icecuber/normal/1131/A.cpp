#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int w1, h1, w2, h2;
  cin >> w1 >> h1 >> w2 >> h2;
  cout << w1+w2+h1*2+h2*2+4+w1-w2 << endl;
}