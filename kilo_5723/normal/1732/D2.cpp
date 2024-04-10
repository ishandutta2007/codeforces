#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 3e18;
const int maxn = 2e5 + 5, buff = 10;
char s[buff];
char op[maxn];
ll x[maxn];
set<ll> st;
map<ll, ll> mp;
map<ll, vector<ll>> dvs;
map<ll, set<ll>> del;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s%lld", s, &x[i]);
    op[i] = s[0];
  }
  st.insert(0);
  for (int i = 0; i < n; i++) switch (op[i]) {
      case '+':
        st.insert(x[i]);
        for (auto k : dvs[x[i]]) del[k].erase(x[i]);
        break;
      case '-':
        st.erase(x[i]);
        for (auto k : dvs[x[i]]) del[k].insert(x[i]);
        break;
      case '?':
        ll k = mp[x[i]];
        while (st.count(k)) {
          dvs[k].push_back(x[i]);
          k += x[i];
        }
        mp[x[i]] = k;
        printf("%lld\n", min(k, del[x[i]].size() ? *del[x[i]].begin() : inf));
        break;
    }
  return 0;
}