#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int prev;
    cin >> prev;
    map<int,int> m;
    for (int i = 1; i < n; i++) {
      int a;
      cin >> a;
      m[a-prev]++;
      prev = a;
    }
    while (m.size() > 1 || m.begin()->second > 1) {
      map<int,int> nm;
      int prev = -1;
      for (auto [v,c] : m) {
        if (c > 1) nm[0] += c-1;
        if (prev != -1) {
          nm[v-prev]++;
        }
        prev = v;
      }
      m = move(nm);
    }
    cout << m.begin()->first << endl;
  }
}