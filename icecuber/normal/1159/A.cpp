#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int mi = 0, sum = 0;
  for (char c : s) {
    sum += (c=='+')*2-1;
    mi = min(mi, sum);
  }
  cout << sum-mi << endl;
}