// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
int stagod, isti;
map<pair<int, int>, char> mp;

void dod(int x, int y, char c) {
  mp[{x, y}] = c;
  auto it = mp.find({y, x});
  if (it != mp.end()) {
    if (it->second == c) {
      isti++;
      stagod++;
    } else {
      stagod++;
    }
  }
}

void skini(int x, int y) {
  auto xit = mp.find({x, y});
  auto it = mp.find({y, x});
  if (it != mp.end()) {
    if (it->second == xit->second) {
      isti--;
      stagod--;
    } else {
      stagod--;
    }
  }
  mp.erase(xit);
}

string yn(int x) {
  return x > 0 ? "YES\n" : "NO\n";
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m;
  while (m--) {
    char op;
    cin >> op;
    if (op == '+') {
      int u, v;
      char c;
      cin >> u >> v >> c;
      dod(u, v, c);
    } else if (op == '-') {
      int u, v;
      cin >> u >> v;
      skini(u, v);
    } else {
      int k;
      cin >> k;
      if (k % 2) {
        cout << yn(stagod);
      } else {
        cout << yn(isti);
      }
    }
  }
}