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
    map<int,int> count;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      count[v]++;
    }
    for (int i = 1; i < 2048; i *= 2) {
      count[i*2] += count[i]/2;
    }
    cout<< (count[2048] ? "YES" : "NO") << endl;
  }
}