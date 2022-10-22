#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  cout << count(s.begin(), s.end(), 'L')+count(s.begin(), s.end(), 'R')+1 << endl;
}