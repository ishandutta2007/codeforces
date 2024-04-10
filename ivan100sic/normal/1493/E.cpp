// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;

void incr(string& s) {
  int k = n-1;
  s[k]++;
  while (s[k] == '2') {
    s[k] = '0';
    k--;
    if (k >= 0) {
      s[k]++;
    } else {
      return;
    }
  }
}

void decr(string& s) {
  int k = n-1;
  s[k]--;
  while (s[k] == '0' - 1) {
    s[k] = '1';
    k--;
    if (k >= 0) {
      s[k]--;
    } else {
      return;
    }
  }
}

void xr(string& a, const string& b) {
  for (int i=0; i<n; i++) {
    if (b[i] == '1') {
      a[i] ^= 1;
    }
  }
}

string prefxor(const string& a) {
  if (n == 1) return a;

  int t = (a[n-2]-'0') * 2 + a[n-1] - '0';

  if (t == 0) {
    return a;
  } else if (t == 1) {
    string r(n-1, '0');
    r += '1';
    return r;
  } else if (t == 2) {
    string b = a;
    b[n-1] = '1';
    return b;
  } else {
    return string(n, '0');
  }
}

string rangexor(string a, const string& b) {
  // cerr << "range xor " << a << ' ' << b << ' ';
  if (a == string(n, '0')) {
    return prefxor(b);
  }

  decr(a);
  a = prefxor(a);
  xr(a, prefxor(b));
  // cerr << a << '\n';
  return a;
}

void brut(string a, string b) {
  string sol = b;

  string a2 = a;
  for (int i=0; i<5; i++) {
    string b2 = b;
    for (int j=0; j<5; j++) {
      if (a2 < b2) {
        sol = max(sol, rangexor(a2, b2));
      } else if (a2 == b2) {
        sol = max(sol, a2);
        break;
      }
      decr(b2);
    }
    if (a2 == b) {
      break;
    }
    incr(a2);
  }

  cout << sol << '\n';
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  string a, b;
  cin >> n >> a >> b;

  if (a[0] != b[0]) {
    cout << string(n, '1') << '\n';
  } else {
    brut(a, b);
  }
}