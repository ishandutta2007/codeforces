#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string a, b;
  cin >> a >> b;
  int a1=0,b1=0;
  for (char c : a) a1 |= c=='1';
  for (char c : b) b1 |= c=='1';
  cout << (a.size()==b.size() && a1==b1 ? "YES" : "NO") << endl;
}