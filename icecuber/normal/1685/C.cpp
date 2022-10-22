#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int argmax(const vector<int>&acc, int l, int r) {
  return max_element(acc.begin()+l, acc.begin()+r)-acc.begin();
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    n *= 2;
    vector<int> acc(n+1);
    int mi = 1e9, ma = -1e9;
    for (int i = 0; i < n; i++) {
      acc[i+1] = acc[i]+(s[i]=='(')-(s[i]==')');
      if (acc[i] < 0) {
        mi = min(mi, i);
        ma = max(ma, i);
      }
    }
    if (mi == 1e9) {
      cout << 0 << endl;
      continue;
    }
    int a = argmax(acc,0,mi), b = argmax(acc, ma+1,n+1);
    int maxi = argmax(acc, 0, n+1);
    if (acc[a]+acc[b] >= acc[maxi]) {
      cout << 1 << endl;
      cout << a+1 << ' ' << b << endl;
    } else {
      cout << 2 << endl;
      cout << 1 << ' ' << maxi << endl;
      cout << maxi+1 << ' ' << n << endl;
    }
  }
}