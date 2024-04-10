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
    int n;
    cin >> n;
    vector<int> a;
    string s;
    cin >> s;
    for (int i=0; i<n; i++) {
      if (s[i] == '*') {
        a.push_back(i);
      }
    }

    ll sol = 0;
    int mid = a.size() / 2;
    for (int i=0; i<(int)a.size(); i++) {
      sol += abs(a[mid] - a[i] - (mid - i));
    }
    cout << sol << '\n';
  }
}