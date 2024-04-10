#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string t;
  int n;
  cin >> t;
  n = t.size();
  string a,b,c;

  cout << "? ";
  for (int i = 0; i < n; i++)
    cout << char(i%26+'a');
  cout << endl;
  cin >> a;
  assert(a != "0");

  cout << "? ";
  for (int i = 0; i < n; i++)
    cout << char(i/26%26+'a');
  cout << endl;
  cin >> b;
  assert(b != "0");

  cout << "? ";
  for (int i = 0; i < n; i++)
    cout << char(i/26/26%26+'a');
  cout << endl;
  cin >> c;
  assert(c != "0");

  vector<char> ans(n);
  for (int i = 0; i < n; i++)
    ans[(a[i]-'a')+26*(b[i]-'a')+26*26*(c[i]-'a')] = t[i];
  cout << "! ";
  for (char c : ans) cout << c; cout << endl;
}