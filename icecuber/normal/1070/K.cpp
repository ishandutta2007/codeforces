#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int sum = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i], sum += a[i];
  if (sum%k) {
    cout << "No" << endl;
    return 0;
  }
  sum /= k;
  vector<int> s(1,0);
  int left = sum;
  for (int i = 0; i < n; i++) {
    if (left >= a[i]) left -= a[i], s[s.size()-1]++;
    else {
      cout << "No" << endl;
      return 0;
    }
    if (!left) s.push_back(0), left = sum;
  }
  if (s.size() != k+1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  for (int i = 0; i < k; i++)
    cout << s[i] << ' ';
  cout << endl;
}