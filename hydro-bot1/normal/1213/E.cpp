// Hydro submission #62c6d57cc3a9fda5622b1e14@1657197987541
#include <iostream>

using namespace std;

int n;

string s, b;

int main() {
  cin >> n >> s >> b;
  cout << "YES" <<endl;
  for (int i = 'a'; i <= 'c'; i++) {
    for (int j = 'a'; j <= 'c'; j++) {
      for (int k = 'a'; k <= 'c'; k++) {
        string x, _i, _j, _k;
        _i.push_back(i);
        _j.push_back(j);
        _k.push_back(k);
        x = _i + _j + _k + _i + _j + _k;
        if (x.find(s) == x.npos && x.find(b) == x.npos && i != j && i != k && j != k) {
          for (; n; n--) {
            cout << _i << _j << _k;
          }
          return 0;
        }
      }
    }
  }
  for (int i = 'a'; i <= 'c'; i++) {
    for (int j = 'a'; j <= 'c'; j++) {
      for (int k = 'a'; k <= 'c'; k++) {
        string x, _i, _j, _k;
        _i.push_back(i);
        _j.push_back(j);
        _k.push_back(k);
        x = _i + _i + _j + _j + _k + _k;
        if (x.find(s) == x.npos && x.find(b) == x.npos && i != j && i != k && j != k) {
          for (int i = n; i; i--) {
            cout << _i;
          }
          for (int i = n; i; i--) {
            cout << _j;
          }
          for (; n; n--) {
            cout << _k;
          }
          return 0;
        }
      }
    }
  }
  return 0;
}