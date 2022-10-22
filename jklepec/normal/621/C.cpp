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

typedef long double lf;
typedef long long llint;
typedef pair<int, int> point;

lf sol;

int p;

int divr(int x, int y) {
   if(x % p != 0)
      x += (p - x % p);
   y -= y % p;
   if(x > y)
      return 0;
   else
      return (y - x) / p + 1;
}

const int MAXN = 200100;

int a[MAXN], b[MAXN];

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int n; cin >> n >> p;
   for(int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
   }
   for(int i = 0; i < n; ++i) {
      int x = i, y = (i + 1) % n;
      int divx = divr(a[x], b[x]);
      int divy = divr(a[y], b[y]);
      int nondivx = b[x] - a[x] - divx + 1;
      int nondivy = b[y] - a[y] - divy + 1;
      llint comb = (llint)divx * nondivy + (llint)divy * nondivx + (llint)divx * divy;
      sol += (lf)2000 * (lf)comb / (lf)((llint)(b[x] - a[x] + 1) * (b[y] - a[y] + 1));
   }
   cout << fixed << sol;
}