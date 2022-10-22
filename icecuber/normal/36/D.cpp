#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t, k;
  cin >> t >> k;
  while (t--) {
    int w, h;
    cin >> w >> h;
    w--, h--;
    if (h > w) swap(w,h);
    cout << (h%(k+1) == k || (w%2+h%2+h/(k+1)*(k>1))%2 ? '+' : '-') << endl;
  }
}