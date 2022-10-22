#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define all(a) (a).begin(), (a).end()
#define gcd(a, b) __gcd(a, b)
#define _ << " " <<

typedef long long llint;
typedef pair<int, int> point;

const llint INF = 1e17;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   llint sum = 0, mp = INF, mn = INF;
   int n; cin >> n;
   for(int i = 0; i < n; ++i) {
      llint x; cin >> x;
      if(x % 2)
         mn = min(mn, x);
      else
         mp = min(mp, x);
      sum += x;
   }
   if(sum % 2)
      cout << sum - mn;
   else
      cout << sum;
}