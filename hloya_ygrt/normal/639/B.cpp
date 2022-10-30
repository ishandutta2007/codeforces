#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define de double
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define sd second
#define ft first

using namespace std;
const ld eps = 1e-9;
const int N = 1e3 + 7, maxn = 200000, inf = 1e9 + 77;



int main() {
  ios_base::sync_with_stdio(0);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, d, h;
  vector <pair <int, int> > ans;
  scanf("%d%d%d", &n, &d, &h);
  if (n >= 3 && d == 1) {
    printf("-1\n");
    return 0;
  }
  if (d > 2 * h) {
    printf("-1\n");
    return 0;
  }
  int all = d - h;

  for (int i = 1; i <= h; i++) {
    ans.pb(mp(i, i + 1));
  }
  for (int i = h + 2; i <= n && i <= h + all + 1; i++) {
    if (i == h + 2) {
      ans.pb(mp(i, 1));
    } else
      ans.pb(mp(i, i - 1));
  }
  for (int i = d + 2; i <= n; i++) {
    if (d == h) {
      ans.pb(mp(2, i));
    } else {
      ans.pb(mp(1, i));
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].ft, ans[i].sd);
  }
}