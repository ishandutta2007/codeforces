#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> a, b;
  string sa, sb;
  int n;
  cin >> n >> sa >> sb;
  a.push_back(0);
  for (char c : sa) a.push_back(c-'a');
  b.push_back(0);
  for (char c : sb) b.push_back(c-'a');
  vector<int> c(n+1, 0);
  int carry = 0;
  for (int i = n; i >= 0; i--) {
    int v = a[i]+b[i]+carry;
    c[i] = v%26;
    carry = v/26;
  }
  assert(!carry);

  /*for (int i = 0; i <= n; i++)
    cout << a[i] << ' ';
  cout << endl;
  for (int i = 0; i <= n; i++)
    cout << b[i] << ' ';
  cout << endl;
  for (int i = 0; i <= n; i++)
    cout << c[i] << ' ';
    cout << endl;*/

  for (int i = 0; i <= n; i++) {
    int v = c[i]+carry;
    c[i] = v/2;
    carry = 26*(v%2);
  }
  assert(!carry);

  /*for (int i = 0; i <= n; i++)
    cout << c[i] << ' ';
  cout << endl;*/


  for (int i = 1; i <= n; i++)
    cout << char(c[i]+'a');
  cout << endl;
}