#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n*2+1; i++) {
    int w = n-abs(i-n);
    for (int j = 0; j < n*2-w*2; j++)
      cout << ' ';
    for (int j = 0; j < w*2+1; j++) {
      if (j) cout << ' ';
      cout << w-abs(j-w);
    }
    cout << endl;
  }
}