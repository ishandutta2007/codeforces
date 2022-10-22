#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int pass = 0, fail = 1e9;
  while (fail-pass > 1) {
    int mid = pass+fail >> 1;
    cout << "> " << mid << endl;
    int ans;
    cin >> ans;
    if (ans) pass = mid;
    else fail = mid;
  }
  int amax = pass+1;
  int g = 0;
  srand(76123);
  for (int i = 0; i < 30; i++) {
    cout << "? " << (rand()*1ll*RAND_MAX+rand())%n+1 << endl;
    int ans;
    cin >> ans;
    g = __gcd(g, amax-ans);
  }
  cout << "! " << amax-(n-1)*g << ' ' << g << endl;
}