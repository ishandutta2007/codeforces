#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c[3] = {};
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      c[a%3]++;
    }
    int k = min(c[1],c[2]);
    cout << c[0]+k+(c[1]+c[2]-k*2)/3 << endl;
  }
}