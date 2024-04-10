#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

typedef pair<int, int> point;
typedef long long llint;

vector<llint> sol;

int main() {
   llint l, r, k;
   cin >> l >> r >> k;
   llint tmp = k;
   llint last = 1LL;
   if(1LL >= l and 1LL <= r)
      sol.push_back(1LL);
   for(; tmp <= 1e18; tmp *= k) {
      if(tmp / k != last)
         break;
      if(tmp >= l and tmp <= r)
         sol.push_back(tmp);
      last = tmp;
   }
   if(sol.empty())
      cout << -1;
   else
      for(llint x : sol)
         cout << x << " ";
   return 0;
}