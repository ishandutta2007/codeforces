#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int f[10];
  for (int i = 1; i < 10; i++)
    cin >> f[i];
  int state = 0;
  for (int i = 0; i < n; i++) {
    int a = s[i]-'0', b = f[a];
    if (state == 0 && b > a) {
      state = 1;
    } else if (state == 1 && b < a)
      state = 2;
    cout << (state == 1 ? b : a);
  }
  cout << endl;
}