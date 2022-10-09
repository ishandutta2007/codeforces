// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, k;
string p[100005];
map<string, int> idx;
basic_string<int> e[100005], sol;
int state[100005];

void dfs(int x) {
  state[x] = 1;
  for (int y : e[x]) {
    if (state[y] == 0) {
      dfs(y);
    } else if (state[y] == 1) {
      cout << "NO\n";
      exit(0);
    }
  }
  state[x] = 2;
  sol += x;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));
  cin >> n >> m >> k;

  for (int i=0; i<n; i++) {
    cin >> p[i];
    idx[p[i]] = i;
  }

  for (int i=0; i<m; i++) {
    string s;
    int id;
    cin >> s >> id;
    id--;

    // proveri
    for (int i=0; i<k; i++) {
      if (s[i] != p[id][i] && p[id][i] != '_') {
        cout << "NO\n";
        return 0;
      }
    }

    for (int mask=0; mask<(1<<k); mask++) {
      string t = s;
      for (int i=0; i<k; i++) {
        if (mask & (1 << i)) {
          t[i] = '_';
        }
      }

      auto it = idx.find(t);
      if (it != idx.end()) {
        int ti = it->second;
        if (ti != id) {
          e[ti] += id;
          // cerr << ti << " --> " << id << '\n';
        }
      }
    }
  }

  for (int i=0; i<n; i++) {
    if (state[i] == 0) {
      dfs(i);
    }
  }

  cout << "YES\n";
  for (int x : sol) {
    cout << x+1 << ' ';
  }
  cout << '\n';
}