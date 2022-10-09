// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string mirror = "015..2..8.";

void inc(string& a, int h, int m) {
  a[4]++;
  if (a[4] == '9' + 1) {
    a[4] = '0';
    a[3]++;
  }

  if ((a[3]-'0') * 10 + a[4]-'0' == m) {
    a[3] = a[4] = '0';
    a[1]++;
    if (a[1] == '9' + 1) {
      a[0]++;
      a[1] = '0';
    }

    if ((a[0]-'0') * 10 + a[1]-'0' == h) {
      a[0] = a[1] = '0';
    }
  }
}

bool good(string a, int h, int m) {
  if (mirror[a[0]-'0'] == '.') return false;
  if (mirror[a[1]-'0'] == '.') return false;
  if (mirror[a[3]-'0'] == '.') return false;
  if (mirror[a[4]-'0'] == '.') return false;

  int ah = (mirror[a[4]-'0']-'0') * 10 + mirror[a[3]-'0']-'0';
  int am = (mirror[a[1]-'0']-'0') * 10 + mirror[a[0]-'0']-'0';

  return am < m && ah < h;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int h, m;
    string a;
    cin >> h >> m >> a;

    while (!good(a, h, m)) {
      inc(a, h, m);
    }

    cout << a << '\n';
  }
}