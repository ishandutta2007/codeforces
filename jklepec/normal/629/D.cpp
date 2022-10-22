#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

#define FOR(i, a, b) for(int i = a; i < b; ++i)

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

const lf pi = 3.14159265359;
const int off = 1 << 17;

vector<pair<lf, int>> v;

const int MAXN = 1e5 + 5;

int ind[MAXN];
int rev[MAXN];

lf a[MAXN];

lf T[2 * off];

void SET(int x, lf val) {
   x += off;
   T[x] = val;

   x /= 2;

   for(; x; x /= 2)
      T[x] = max(T[x * 2], T[x * 2 + 1]);
}

lf GET(int x, int lo, int hi, int a, int b) {
   if(lo >= b || hi <= a)
      return (lf)0;
   if(lo >= a && hi <= b)
      return T[x];

   int mid = (lo + hi) >> 1;

   return max(GET(x * 2, lo, mid, a, b), GET(x * 2 + 1, mid, hi, a, b));
}

lf pov[MAXN];

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);

   int n; cin >> n;

   FOR(i, 0, n) {
      lf r, h;
      cin >> r >> h;

      a[i] = r * r * pi * h;
      v.push_back(make_pair(a[i], i));
   }

   sort(v.begin(), v.end());

   FOR(i, 0, n) {
      ind[v[i].S] = i + 1;
      rev[i + 1] = v[i].S;
      pov[i + 1] = v[i].F;
   }

   SET(ind[0], a[0]);

   lf sol = a[0];

   FOR(i, 1, n) {
      int lo = 0, hi = n + 1;
      while(lo  < hi) {
         int mid = (lo + hi + 1) >> 1;
         if(pov[mid] >= a[i])
            hi = mid - 1;
         else
            lo = mid;
      }

      sol = max(GET(1, 0, off, 0, lo + 1) + a[i], sol);

      SET(ind[i], GET(1, 0, off, 0, lo + 1) + a[i]);
   }

   cout << fixed << setprecision(10) << sol;
}