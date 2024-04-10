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
    vector<int> a(n), b(n);
    for (int&v : a) cin >> v;
    for (int&v : b) cin >> v;

    vector<int> cnt(n+1);
    int i = 0;
    for (int j = 0; j < n; j++) {
      if (j && b[j] == b[j-1] && cnt[b[j]]) {
        cnt[b[j]]--;
        continue;
      }
      while (i < n && a[i] != b[j]) {
        cnt[a[i]]++;
        i++;
      }
      if (i == n) goto fail;
      i++;
    }

    cout << "YES" << endl;
    continue;
fail:
    cout << "NO" << endl;
  }
}