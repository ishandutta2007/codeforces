#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep1(i, n) for(int i = 1; i < n; ++i)
#define _ << " " <<

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

const int MAXN = 2e5 + 5, M = 1e9 + 7, p1 = 105023, p2 = 15486277, p3 = 179425033;

vector<int> v;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   int n, p; cin >> n >> p;

   ll sol = 0;

   for(int i = 0; i < n; ++i) {
      string x; cin >> x;
      v.push_back(x != "half");
   }

   ll tmp = 0;

   for(int i = n - 1; i >= 0; --i) {
       if(v[i])
         sol += (ll)tmp * p + p / 2;
       else
         sol += (ll)tmp * p;
       tmp *= 2;
       tmp += v[i];
   }

   cout << sol;
}