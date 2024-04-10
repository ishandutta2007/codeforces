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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), d(n), sol(n, -1);
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }
    for (int i=0; i<n; i++) {
      char c;
      cin >> c;
      d[i] = c == 'R' ? 1 : -1;
    }

    vector<int> e;

    auto go = [&]() {
      sort(begin(e), end(e), [&](int x, int y) { return a[x] < a[y]; });
      basic_string<int> st;
      for (int i : e) {
        if (st.empty()) {
          st += i;
          continue;
        }

        if (d[i] == -1) {
          int j = st.back();
          st.pop_back();
          if (d[j] == 1) {
            sol[j] = sol[i] = (a[i] - a[j]) / 2;
          } else {
            sol[j] = sol[i] = (a[i] + a[j]) / 2;
          }
        } else {
          st += i;
        }
      }

      // st: (-1)? (1)*
      while (st.size() >= 2) {
        int i = st[st.size() - 2];
        int j = st[st.size() - 1];
        if (d[i] == 1 && d[j] == 1) {
          st.pop_back();
          st.pop_back();
          sol[i] = sol[j] = (m-a[i] + m-a[j]) / 2;
        } else {
          break;
        }
      }

      if (st.size() == 2) {
        // -1 1
        int i = st[st.size() - 2];
        int j = st[st.size() - 1];
        sol[i] = sol[j] = (2*m-a[j]+a[i]) / 2;
      }
    };

    for (int r : {0, 1}) {
      e = {};
      for (int i=0; i<n; i++) {
        if (a[i] % 2 == r) {
          e.push_back(i);
        }
      }
      go();
    }

    for (int i=0; i<n; i++) {
      cout << sol[i] << " \n"[i == n-1];
    }
  }
}