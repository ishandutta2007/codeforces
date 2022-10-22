#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int best_count = 0, best_num;
  map<int,int> count;
  for (int&i : a) {
    cin >> i;
    int c = ++count[i];
    if (c > best_count) {
      best_count = c;
      best_num = i;
    }
  }
  cout << n-best_count << endl;
  for (int i = 1; i < n; i++) {
    if (a[i-1] == best_num && a[i] != best_num) {
      cout << 1+(a[i]>a[i-1]) << ' ' << i +1 << ' ' << i-1 +1 << endl;
      a[i] = a[i-1];
    }
  }
  for (int i = n-2; i >= 0; i--) {
    if (a[i+1] == best_num && a[i] != best_num) {
      cout << 1+(a[i]>a[i+1]) << ' ' << i +1 << ' ' << i+1 +1 << endl;
      a[i] = a[i+1];
    }
  }
}