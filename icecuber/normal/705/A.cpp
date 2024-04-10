#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  string s = "I "+(n%2?string("hate"):string("love"))+" it";
  for (int i = 1; i < n; i++) {
    if (n-i&1)
      s = "I hate that "+s;
    else
      s = "I love that "+s;
  }
  cout << s << endl;
}