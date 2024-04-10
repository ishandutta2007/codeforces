// Hydro submission #620232797af21c4515fb470e@1644311162675
#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;
using vi = vector<int>;

vi dfs(vi a, int d) {
  // 
  sort(a.begin(), a.end()), a.erase(unique(a.begin(), a.end()), a.end());
  // 
  if (a.size() == 1 && a[0] == 0) return vi();
  if (d >= 20) return vi(20);
  // 
  bool odd = false;
  for (int x : a)
    if (x & 1) odd = true;
  if (!odd) {
    for (int &x : a) x >>= 1;
    return dfs(a, d + 1);
  }
  //  -1
  vi b = a, ans1, ans2;
  for (int &x : b) x += x & 1;
  ans1 = dfs(b, d), ans1.emplace_back(-(1 << d));
  //  1
  b = a;
  for (int &x : b) x -= x & 1;
  ans2 = dfs(b, d), ans2.emplace_back(1 << d);
  return ans1.size() < ans2.size() ? ans1 : ans2;
}

template <typename T>
void read(T &ret) {
  ret = 0;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  bool vis = ch == '-' && (ch = getchar());
  while (isdigit(ch)) ret = ret * 10 + ch - '0', ch = getchar();
  if (vis) ret = -ret;
}

template <typename T, typename... Arg>
void read(T &ret, Arg &...arg) {
  read(ret), read(arg...);
}

int main() {
  int n;
  read(n);
  vi a(n);
  for (int i = 0; i < n; i++) read(a[i]);
  vi ans = dfs(a, 0);
  cout << ans.size() << endl;
  for (int x : ans) printf("%d ", x);
  return puts(""), 0;
}