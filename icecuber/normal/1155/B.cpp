#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int eights = 0;
  for (int i = 0; i < n-10; i++)
    eights += s[i] == '8';
  cout << (eights > (n-10)/2 ? "YES" : "NO") << endl;
}