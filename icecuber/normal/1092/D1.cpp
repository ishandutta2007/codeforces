#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  stack<int> s;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a %= 2;
    if (s.size() && a == s.top()) s.pop();
    else s.push(a);
  }
  cout << (s.size() < 2 ? "YES" : "NO") << endl;
}