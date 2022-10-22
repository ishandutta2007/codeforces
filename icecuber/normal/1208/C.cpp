#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000][1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < n; j += 2) {
      int v = (i/2*(n/2)+j/2)*4;
      a[i][j] = v;
      a[i+1][j] = v+1;
      a[i][j+1] = v+2;
      a[i+1][j+1] = v+3;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << a[i][j] << ' ';
    cout << endl;
  }
}