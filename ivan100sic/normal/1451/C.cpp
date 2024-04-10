// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;

    vector<int> p(26), q(26);
    for (char x : a) p[x-'a']++;
    for (char x : b) q[x-'a']++;

    for (int i=0; i<25; i++) {
      while (p[i] > q[i] && p[i] >= k) {
        p[i] -= k;
        p[i+1] += k;
      }
    }

    cout << (p == q ? "Yes\n" : "No\n");
  }
}