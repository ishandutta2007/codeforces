// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, c;
int a[200005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> c >> n;
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }

  vector<int> b;
  for (int i=1; i<=c; i++) {
    if (a[i]) {
      b.push_back(i);
    }
  }

  for (int x=1; x<=c; x++) {
    int hasx = 0, dec = 1, use = b.size();
    if (a[x]) {
      dec = 1;
      a[x]++;
    } else {
      hasx = 1;
    }

    int t = c;
    while (t > 0) {
      auto it = upper_bound(begin(b), begin(b)+use, t) - begin(b);

      if (it == 0) {
        if (hasx && x <= t) {
          t -= x;
          hasx = 0;
        } else {
          break;
        }
      } else {
        it--;
        int y = b[it];
        if (hasx && x <= t && x > y) {
          t -= x;
          hasx = 0;
        } else {
          t -= min(a[y], t / y) * y;
          use = it;
        }
      }
    }

    if (t > 0) {
      cout << x << '\n';
      return 0;
    }

    if (dec) {
      a[x]--;
    }
  }

  cout << "Greed is good\n";
}