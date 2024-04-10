#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <limits>
 
using namespace std;
 
long long mygcd(long long a, long long b) {
  while (b) {
    long long t = a %b;
    a = b;
    b = t;
  }
  return a;
}
 
int main() {
  long long n, m;
  int q;
  scanf("%lld%lld%d", &n, &m, &q);
  long long g = mygcd(n, m);
  long long inp = n / g;
  long long outp = m / g;
  while (q-- > 0) {
    long long sx, sy, ex, ey;
    scanf("%lld%lld", &sx, &sy);
    scanf("%lld%lld", &ex, &ey);
    sx--, sy--;
    ex--, ey--;
    long long a, b;
    if (sx == 0) a = sy / inp;
    else a = sy / outp;
    if (ex == 0) b = ey / inp;
    else b = ey / outp;
    if (a != b) {
      puts("NO");
    } else {
      puts("YES");
    }
  }
  return 0;
}