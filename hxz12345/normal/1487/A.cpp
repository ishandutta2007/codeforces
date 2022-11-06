#include <algorithm>
#include <iostream>
using namespace std;
const int kMaxN = 101;
int n, t, a[kMaxN], ans;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) 
      cin >> a[i];
    sort(a + 1, a + 1 + n); 
    for (int i = 2; i <= n; i++) {
      if (a[i] > a[1]) ans++;  
    }
    cout << ans << endl;  
    ans = 0;              
  }
  return 0;
}