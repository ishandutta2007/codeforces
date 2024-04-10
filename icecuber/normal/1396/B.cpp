#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int&v : a) cin >> v, sum += v;
    int ma = *max_element(a.begin(), a.end());
    if (sum%2 || ma*2 > sum) cout << "T" << endl;
    else cout << "HL" << endl;
  }
}