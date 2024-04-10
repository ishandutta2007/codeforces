#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define all(a) (a).begin(), (a).end()
#define gcd(a, b) __gcd(a, b)
#define _ << " " <<

using namespace std;

typedef long long int64;
typedef pair<int, int> point;

int a[55];
bool took = false;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int n; cin >> n;
   FOR(i, 0, n) {
      int mx = 0;
      FOR(j, 0, n) {
         int x; cin >> x;
         mx = max(mx, x);
      }
      if(mx != n - 1)
         cout << mx << " ";
      else if(took)
         cout << n << " ";
      else {
         took = true;
         cout << n - 1 << " ";
      }
   }
}