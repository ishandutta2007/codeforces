// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int a0;
  string s;
  cin >> a0 >> s;

  const char* p = s.c_str();

  vector<pair<int, int>> v;

  bool first = true;
  while (*p) {
    int y = 1, mul = 1;
    if (!first) {
      if (*p == '-') {
        mul = -1;
      }
      p++;
    }

    if (isdigit(*p)) {
      int x = *p - '0';
      p++;
      while (isdigit(*p)) {
        x = 10 * x + *p - '0';
        p++;
      }
      y = x;
      p++; // *
    }
    if (*p == 'a') {
      // a++
      p += 3;
      v.emplace_back(y * mul, 0);
    } else {
      // ++a
      p += 3;
      v.emplace_back(y * mul, 1);
    }

    first = false;
  }

  sort(begin(v), end(v), [](auto a, auto b) {
    return a.first < b.first;
  });

  ll sol = 0;
  for (int i=0; i<(int)v.size(); i++) {
    cerr << v[i].first << ' ' << v[i].second << '\n';
    sol += v[i].first * (a0 + i + v[i].second);
  }

  cout << sol << '\n';
}

/*
F * (b + S) + f * (b + 1 + s)
?
f * (b + s) + F * (b + 1 + S)

Fb + FS + fb + f + fs
?
fb + fs + Fb + F + FS

f F



*/