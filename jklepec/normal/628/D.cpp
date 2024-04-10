#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, a, b) for(int i = a; i < b; ++i)

const int MAXN = 2e3 + 5, M = 1e9 + 7;

int n, m, d;

string a, b;

bool up[MAXN];
bool dw[MAXN];

ll dp[MAXN];
ll ldp[MAXN];

int des[MAXN];

int mul(int a, int b) {
   return (ll)a * b % m;
}

int check(const string &s) {
   int k = 0;
   for(int i = 0; i < n; ++i) {
      if((i % 2) && s[i] - '0' != d)
         return 0;
      if((i + 1) % 2 && s[i] - '0' == d)
         return 0;
      k = (k + mul(s[i] - '0', des[n - 1 - i])) % m;
   }
   return k == 0 ? 1 : 0;
}

int solve() {

   for(int i = a[0] - '0' + 1; i < b[0] - '0'; ++i)
      if(i != d)
         dp[mul(i, des[n - 1])] ++;

   for(int i = 1; i < n; ++i) {
      memcpy(ldp, dp, sizeof ldp);
      memset(dp, 0, sizeof dp);

      vector<int> zn;

      if(i % 2)
         zn.push_back(d);
      else
         for(int i = 0; i < 10; ++i)
            if(i != d)
               zn.push_back(i);

      for(auto x : zn) {
         for(int j = 0; j < m; ++j) {
            dp[(j + mul(x, des[n - i - 1])) % m] += ldp[j];
            dp[(j + mul(x, des[n - i - 1])) % m] %= M;
         }
         if(up[i - 1] && x < b[i] - '0' && !(a.substr(0, i) == b.substr(0, i) && x <= a[i] - '0')) {
            int k = 0;
            for(int j = 0; j < i; ++j)
               k = (k + mul(des[n - 1 - j], b[j] - '0')) % m;
            dp[(k + mul(x, des[n - 1 - i])) % m] ++;
         }
         if(dw[i - 1] && x > a[i] - '0' && !(a.substr(0, i) == b.substr(0, i) && x >= b[i] - '0')) {
            int k = 0;
            for(int j = 0; j < i; ++j)
               k = (k + mul(des[n - 1 - j], a[j] - '0')) % m;
            dp[(k + mul(x, des[n - 1 - i])) % m] ++;
         }
      }
   }

   return (dp[0] + check(a) + (a != b ? check(b) : 0)) % M;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);

   cin >> m >> d >> a >> b;

   n = a.size();

   des[0] = 1 % m;

   for(int i = 1; i < MAXN; ++i)
      des[i] = des[i - 1] * 10 % m;

   up[0] = !(b[0] - '0' == d);
   dw[0] = !(a[0] - '0' == d);

   for(int i = 0; i < n; ++i) {
      if(i % 2) {
         if(b[i] - '0' != d)
            up[i] = false;
         else
            up[i] = up[i - 1];

         if(a[i] - '0' != d)
            dw[i] = false;
         else
            dw[i] = dw[i - 1];
      }
      else if(i > 0) {
         if(b[i] - '0' == d)
            up[i] = false;
         else
            up[i] = up[i - 1];

         if(a[i] - '0' == d)
            dw[i] = false;
         else
            dw[i] = dw[i - 1];
      }
   }

   cout << solve();

}