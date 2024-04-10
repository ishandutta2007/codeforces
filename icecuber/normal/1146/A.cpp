#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int as = count(s.begin(), s.end(), 'a');
  int n = s.size();
  cout << min(n, as*2-1) << endl;
}