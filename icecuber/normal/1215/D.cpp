#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int balance = 0;
  for (int i = 0; i < n; i++) {
    int w = i < n/2 ? 1 : -1;
    if (s[i] == '?') balance += 9*w;
    else balance += (s[i]-'0')*2*w;
  }
  cout << (balance == 0 ? "Bicarp" : "Monocarp") << endl;
}