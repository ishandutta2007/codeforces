#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[200000];
int rem[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < a.size(); i++) cin >> p[i];
  int pass = 0, fail = a.size();
  while (abs(fail-pass) > 1) {
    int mid = fail+pass>>1;
    fill_n(rem, a.size(), 0);
    for (int i = 0; i < mid; i++)
      rem[p[i]-1] = 1;
    int j = 0;
    for (int i = 0; i < a.size(); i++)
      if (!rem[i] && j < b.size() && a[i] == b[j]) j++;
    if (j == b.size()) pass = mid;
    else fail = mid;
  }
  cout << pass << endl;
}