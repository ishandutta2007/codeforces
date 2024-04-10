#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[1000000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  int swaps = 0;
  for (int i = 0; i < n; i++) {
    while (p[i] != i) {
      swap(p[i], p[p[i]]);
      swaps++;
    }
  }
  cout << (n%2 == swaps%2 ? "Petr" : "Um_nik") << endl;
}