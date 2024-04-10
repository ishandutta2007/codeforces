#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5, buff = 10;
char s[buff];
char op[maxn];
ll x[maxn];
set<ll> st;
map<ll, ll> mp;
// vector<ll> adds[maxn], dels[maxn];
// void init(int n) {}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s%lld", s, &x[i]);
    op[i] = s[0];
  }
  st.insert(0);
  // init(n);
  // for (int i = 0; i < n; i++) printf("%c %lld\n", op[i], x[i]);
  for (int i = 0; i < n; i++) switch (op[i]) {
      case '+':
        st.insert(x[i]);
        break;
      case '-':
        st.insert(x[i]);
        break;
      case '?':
        mp[x[i]] = mp[x[i]];
        auto it = mp.find(x[i]);
        auto &k = it->second;
        while (st.count(k)) k += x[i];
        printf("%lld\n", k);
        mp[x[i]] = k;
        break;
    }
  return 0;
}