#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;

ll sol;

int n, remove_cost, add_cost;
int dp[MAXN];

vector<int> a, pf;

void init(int x) {
   for(int j = -1; j <= 1; ++j) {
      int A = a[x] + j;

      for(int i = 2; i * i <= a[x] + j; ++i) {
         if(A % i == 0)
            pf.push_back(i);
         while(A % i == 0) A /= i;
      }

      if(A > 1)
         pf.push_back(A);
   }
}

void solve() {
   for(auto d : pf) {
      if(d < 2)
         continue;

      int fr = -1, ls = -1, uk = 0;
      memset(dp, 0, sizeof dp);

      for(int i = 0; i < n; ++i) {
         if(a[i] % d == 0)
            dp[i] = 0;
         else if((a[i] + 1) % d == 0 || (a[i] - 1) % d == 0)
            dp[i] = 1, uk ++;
         else {
            dp[i] = -1;
            if(fr == -1) fr = i;
            ls = i;
         }
      }

      ll best = 0LL;
      int imam = 0;

      for(int i = 0; i < n; ++i) {
         if(dp[i] == 1) imam ++;
         ll f = (ll)imam * add_cost - (ll)(i + 1) * remove_cost;
         if(i < fr || fr == -1)
            best = min(best, f);
         if(i >= ls)
            sol = min(sol, (ll)uk * add_cost - f + best);
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);

   cin >> n; a.reserve(n);
   cin >> remove_cost >> add_cost;

   sol = ll(remove_cost) * (n - 1);

   for(int i = 0; i < n; ++i)
      cin >> a[i];

   init(0); init(n - 1);

   solve();
   reverse(a.begin(), a.begin() + n);
   solve();
   cout << sol << '\n';
   return 0;
}