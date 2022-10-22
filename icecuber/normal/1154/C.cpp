#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int arr[7] = {0,1,2,0,2,1,0};
  int ans = 0;
  int a, b, c;
  cin >> a >> b >> c;
  int w = min({a/3,b/2,c/2});
  for (int d = 0; d < 7; d++) {
    int A[3] = {a-w*3,b-w*2,c-w*2};
    for (int i = 0; i < 7; i++) {
      ans = max(ans, w*7+i);
      if (!A[arr[(d+i)%7]]--) break;
    }
  }
  cout << ans << endl;
}