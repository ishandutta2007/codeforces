#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int zeros = count(s.begin(), s.end(), 'z');
  int ones = (n-zeros*4)/3;
  for (int i = 0; i < ones; i++)
    cout << 1 << ' ';
  for (int i = 0; i < zeros; i++)
    cout << 0 << ' ';
  cout << endl;
}