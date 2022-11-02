#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int a[maxn];
vector<ll> s;
vector<int> d, p;
// struct cmp {
//   bool operator()(int a, int b) { return s[a] > s[b]; }
// };
set<pair<ll,int>> st;
bool isprime(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    s.clear();
    d.clear();
    p.clear();
    for (int i = n - 1; i >= 1; i--)
      if (!(n % i) && isprime(n / i)) {
        d.push_back(i);
        p.push_back(s.size());
        for (int j = 0; j < i; j++) {
          s.push_back(0);
          for (int k = j; k < n; k += i) s.back() += (ll)a[k] * i;
        }
      }
    st.clear();
    for (int i = 0; i < s.size(); i++) st.insert({s[i],i});
    printf("%lld\n", st.rbegin()->first);
    while (q--) {
      int t, x;
      scanf("%d%d", &t, &x);
      t--;
      for (int i = 0; i < d.size(); i++) {
        int k = p[i] + t % d[i];
        st.erase({s[k],k});
        s[k] += (ll)d[i] * (x - a[t]);
        st.insert({s[k],k});
      }
      a[t] = x;
      printf("%lld\n", st.rbegin()->first);
    }
  }
  return 0;
}