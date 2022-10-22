#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> point;
typedef unsigned long long ll;
typedef double lf;

const int MAX = 1e4 + 100, MAXN = 2e3 + 5;

ll dp1[MAX];
ll dp2[MAX];
ll dp3[MAX];

int a[MAXN];

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int n; cin >> n;

   for(int i = 0; i < n; ++i)
      cin >> a[i];
   sort(a, a + n);

   for(int i = 0; i < n; ++i)
      for(int j = i + 1; j < n; ++j)
         dp1[a[j] - a[i]] ++;

   for(int i = 0; i < MAX / 2; ++i)
      if(dp1[i])
         for(int j = 0; j < MAX / 2; ++j)
            if(dp1[j])
               dp2[i + j] += dp1[i] * dp1[j];

   for(int i = MAX - 2; i; --i)
      dp3[i] = dp3[i + 1] + dp1[i];

   ll sol = 0;
   for(int i = 0; i < MAX - 1; ++i)
      sol += dp2[i] * dp3[i + 1];

   ll uk = (ll)(n * (n - 1) / 2) * (ll)(n * (n - 1) / 2) * (ll)(n * (n - 1) / 2);

   cout << fixed << setprecision(10) << (lf)sol / (lf)uk;

}