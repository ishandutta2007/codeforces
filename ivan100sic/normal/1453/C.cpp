// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string s[2005];
int n;
int sol[10];

void mx(int& x, int y) {
  x = max(x, y);
}

int f[2005], l[2005];

void g() {
  for (int x=0; x<10; x++) {
    for (int i=0; i<n; i++) {
      f[i] = l[i] = -1;
      for (int j=0; j<n; j++) {
        if (s[i][j] - '0' == x) {
          if (f[i] == -1) f[i] = j;
          l[i] = j;
        }
      }
    }

    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        if (f[i] != -1 && l[j] != -1) {
          mx(sol[x], abs(j-i) * max(n-1-f[i], l[j]));
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    for (int i=0; i<n; i++) {
      cin >> s[i];
    }

    fill(sol, sol+10, 0);

    g();
    for (int i=0; i<n; i++) {
      for (int j=i+1; j<n; j++) {
        swap(s[i][j], s[j][i]);
      }
    }
    g();

    for (int i=0; i<10; i++) {
      cout << sol[i] << " \n"[i == 9];
    }
  }
}