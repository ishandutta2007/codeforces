#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string vowel = "aeiou";
  int k;
  cin >> k;
  for (int w = 5; w < k; w++) {
    int h = k/w;
    if (w*h != k || h < 5) continue;
    string ans;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
	ans += vowel[(i+j)%5];
    cout << ans << endl;
    return 0;
  }
  cout << -1 << endl;
}