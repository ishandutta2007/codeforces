#include <cstdio>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    map<ll, ll> mp;
    multiset<int, greater<int> > st;
    int n;
    ll sum = 0;
    scanf("%d",&n);
    while (n--) {
      int t;
      scanf("%d", &t);
      st.insert(t);
      sum += t;
    }
    bool flg = true;
    mp[sum] = 1;
    while (mp.size()) {
      auto it = mp.end();
      it--;
      if (!st.size() || *st.begin() > it->first) {
        flg = false;
        break;
      }
      while (st.size() && *st.begin() == it->first && it->second) {
        st.erase(st.begin());
        it->second--;
      }
      if (it->first!=1&&it->second) {
        mp[it->first / 2] += it->second;
        mp[(it->first + 1) / 2] += it->second;
      }
      mp.erase(it);
    }
    puts(flg&&!st.size()?"YES":"NO");
  }
  return 0;
}