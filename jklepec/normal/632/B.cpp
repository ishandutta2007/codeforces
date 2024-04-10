#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep1(i, n) for(int i = 1; i < n; ++i)
#define _ << " " <<

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

const int MAXN = 5e5 + 5, M = 1e9 + 7, p1 = 105023, p2 = 15486277, p3 = 179425033;

ll sol;
int a[MAXN];

void solve(const string &s, const int &n) {

   ll A = 0, B = 0;

   rep(i, n) {
      if(s[i] == 'A')
         A += a[i];
      else
         B += a[i];
   }

   sol = max(sol, B);

   ll A2 = 0, B2 = 0;

   rep(i, n) {
      if(s[i] == 'A') {
         A -= a[i];
         B2 += a[i];
      }
      else {
         B -= a[i];
         A2 += a[i];
      }
      sol = max(sol, B + B2);
   }

}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   int n; cin >> n;

   rep(i, n)
      cin >> a[i];

   string s; cin >> s;

   solve(s, n);
   reverse(a, a + n);
   reverse(s.begin(), s.end());
   solve(s, n);

   cout << sol;
}