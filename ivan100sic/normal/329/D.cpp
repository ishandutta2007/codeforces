// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, k;
  cin >> n >> k;
  if (n == 5) {
    cout << ">...v\n";
    cout << "v.<..\n";
    cout << "..^..\n";
    cout << ">....\n";
    cout << "..^.<\n";
    cout << "1 1\n";
  } else if (n == 3) {
    cout << ">vv\n";
    cout << "^<.\n";
    cout << "^.<\n";
    cout << "1 3\n";
  } else {
    vector<string> a(100, string(100, '.'));
    a[0][0] = 'v';
    a[1][99] = '^';
    for (int i=0; i<35; i++) {
      a[1][i] = '>';
    }
    for (int i=36; i<99; i+=2) {
      a[1][i] = '>';
    }

    for (int i=0; i<32; i++) {
      a[0][99-i] = '<';
    }

    for (int i=34; i<99; i+=2) {
      a[0][99-i] = '<';
    }

    for (int i=2; i<100; i++) {
      a[i] = a[i-2];
    }

    for (string s : a) cout << s << '\n';
    cout << "100 1\n";
  }

}