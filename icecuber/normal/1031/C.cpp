#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  ll a, b;
  cin >> a >> b;
  ll s = 0;
  ll i = 1;
  for (; s+i <= a; i++)
    s += i;
  ll skipped = i-(a-s);
  cout << i-1 << endl;
  i++;
  for (int j = 1; j < i; j++)
    if (j != skipped) cout << j << ' ';
  cout << endl;
  vector<int> blist;
  if (skipped <= b) {
    b -= skipped;
    blist.push_back(skipped);
  }
  while (b >= i) {
    b -= i;
    blist.push_back(i++);
  }
  cout << blist.size() << endl;
  for (int i : blist) cout << i << ' ';
  cout << endl;
}