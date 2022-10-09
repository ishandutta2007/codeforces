// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int pc(int x) {
  return bitset<32>(x).count();
}

void brutina(int a, int b) {
  int w = 1 << (a+b-1);
  vector<int> v;
  for (int x=w; x<2*w; x++) {
    if (pc(x) == b) {
      v.push_back(x);
    }
  }

  map<int, array<int, 3>> m;

  int n = v.size();
  for (int i=0; i<n; i++) {
    for (int j=i; j<n; j++) {
      int d = v[j] - v[i];
      m[pc(d)] = {d, v[j], v[i]};
    }
  }

  for (auto [x, v] : m) {
    cout << x;
    for (int y : v) {
      cout << ' ' << bitset<16>(y).to_string();
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int a, b, k;
  cin >> a >> b >> k;
  // brutina(a, b);

  if (a == 0 || b == 1) {
    // nema izbora
    if (k == 0) {
      cout << "Yes\n";
      string s = string(b, '1') + string(a, '0') + '\n';
      cout << s+s;
    } else {
      cout << "No\n";
    }
    return 0;
  }

  if (k <= a+b-2) {
    cout << "Yes\n";
    cout << string(b, '1') << string(a, '0') << '\n';
    if (k <= a) {
      cout << string(b-1, '1') << string(k, '0') << '1' << string(a-k, '0') << '\n';
    } else {
      cout << string(a+b-k-1, '1') << '0' << string(k-a, '1') << string(a-1, '0') << "1\n";
    }
  } else {
    cout << "No\n";
  }
}