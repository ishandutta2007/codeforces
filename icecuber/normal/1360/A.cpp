#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int n = max(min(w,h)*2,max(w,h));
    cout << n*n << endl;
  }
}