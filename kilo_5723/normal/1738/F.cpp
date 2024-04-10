#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e3 + 5;
int d[maxn], f[maxn], o[maxn], v[maxn];
int ff(int u) { return f[u] == u ? u : f[u] = ff(f[u]); }
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) o[i] = i + 1;
    sort(o, o + n, [](int a, int b) { return d[a] > d[b]; });
    for (int i = 1; i <= n; i++) {
      f[i] = i;
      v[i] = false;
    }
    for (int i = 0; i < n; i++)
      if (!v[o[i]]) {
        int u = o[i];
        v[u] = true;
        for (int j = 0; j < d[u]; j++) {
          cout << "? " << u << endl;
          int t;
          cin >> t;
          if (v[t]) {
            f[u] = t;
            break;
          }
          v[t] = true;
          f[t] = u;
        }
      }
    cout << "!";
    for (int i = 1; i <= n; i++) cout << ' ' << ff(i);
    cout << endl;
  }
  return 0;
}