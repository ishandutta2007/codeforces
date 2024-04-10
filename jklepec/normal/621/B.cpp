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

const int MAX = 1e4 + 5;

int num[MAX];
int num2[MAX];

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int n; cin >> n; llint sol = 0;
   for(int i = 0; i < n; ++i) {
      int x, y; cin >> x >> y;
      num[x + y]++;
      num2[x - y + (int)1e3 + 5]++;
   }
   for(int i = 0; i < MAX; ++i) {
      sol += (llint)num[i] * (llint)(num[i] - 1);
      sol += (llint)num2[i] * (llint)(num2[i] - 1);
   }
   cout << sol / 2;
}