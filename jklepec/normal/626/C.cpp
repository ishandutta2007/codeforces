#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int N, M;

   cin >> N >> M;

   int lo = 0, hi = 1e7;

   if(N == 0) {
      cout << M * 3;
      return 0;
   }
   if(M == 0) {
      cout << N * 2;
      return 0;
   }

   while(lo < hi) {
      int mid = (lo + hi) / 2;
      bool can = true;
      int n = N, m = M;
      int tr = mid / 3 - mid / 6;
      int dv = mid / 2 - mid / 6;
      n = max(0, n - dv);
      m = max(0, m - tr);
      if(n + m > mid / 6)
         can = false;
      if(can)
         hi = mid;
      else
         lo = mid + 1;
   }
   cout << lo;
}