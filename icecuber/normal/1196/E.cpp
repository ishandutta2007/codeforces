#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int b, w;
    cin >> b >> w;
    int off = 0;
    if (w > b) swap(b,w), off++;
    if (b > w*3+1) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = (w==b); i < w*2+1; i++) {
      cout << i+1 << ' ' << 2+off << endl;
    }
    b -= w+!(w==b);
    for (int i = 0; i < min(b,w); i++)
      cout << i*2+2 << ' ' << 1+off << endl;
    b -= min(b,w);
    for (int i = 0; i < min(b,w); i++)
      cout << i*2+2 << ' ' << 3+off << endl;
  }
}