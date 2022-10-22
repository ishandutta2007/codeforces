#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e5 + 5;

bool can[MAXN][5];

vector<string> sol;

int main() {
   //ios_base::sync_with_stdio(false); cin.tie(0);
   string s; cin >> s;
   int n = s.size();

   s += "###";

   can[n][2] = can[n][3] = true;

   for(int i = n - 1; i >= 0; --i) {
      if(i <= 4) break;
      if(can[i + 2][2] && s.substr(i, 2) != s.substr(i + 2, 2) || can[i + 2][3]) {
         can[i][2] = true;
      }
      if(can[i + 3][2] || can[i + 3][3] && s.substr(i, 3) != s.substr(i + 3, 3)) {
         can[i][3] = true;
      }
   }
   rep(i, n) {
      if(i < 5) continue;
      if(can[i][2])
         sol.push_back(s.substr(i, 2));
      if(can[i][3])
         sol.push_back(s.substr(i, 3));
   }

   int sz = 0;
   sort(sol.begin(), sol.end());
   rep(i, sol.size()) {
      if(!i || sol[i] != sol[i - 1]) sz ++;
   }
   cout << sz << '\n';
   rep(i, sol.size()) {
      if(!i || sol[i] != sol[i - 1])
         cout << sol[i] << '\n';
   }
}