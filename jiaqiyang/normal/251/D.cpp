#include <cstdio>
#include <cassert>
#include <bitset>
#include <vector>
#include <algorithm>

typedef unsigned long long u64;

const int N = 100000 + 10;

int n, BIT;
u64 num[N];

std::vector< std::bitset<N> > eq;
std::vector<int> tag;

bool gauss(std::bitset<N> &cur) {
  for (int i = 0; i < eq.size(); ++i) if (cur[tag[i]]) cur ^= eq[i];
  if (cur[n + 1] == 1 && cur.count() == 1) return false;
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  u64 s = 0;
  for (int i = 1; i <= n; ++i) scanf("%I64u", num + i), s ^= num[i];
  BIT = 63 - __builtin_clzll(*std::max_element(num + 1, num + n + 1));
  u64 x1 = 0;
  for (int k = 0; k < 2; ++k) {
    for (int i = BIT; i >= 0; --i) {
      if ((s >> i & 1) == k) {
        if (!k) x1 ^= 1ULL << i;
        std::bitset<N> temp;
        for (int j = 1; j <= n; ++j) temp[j] = num[j] >> i & 1;
        temp[n + 1] = x1 >> i & 1;
        if (!gauss(temp)) {
          x1 ^= 1ULL << i;
          for (int j = 1; j <= n; ++j) temp[j] = num[j] >> i & 1;
          temp[n + 1] = x1 >> i & 1;
        }
        assert(gauss(temp));
        if (temp.any()) {
          eq.push_back(temp);
          for (int j = 1; j <= n; ++j) {
            if (temp[j]) {
              tag.push_back(j);
              break;
            }
          }
        }
      }
    }
  }
  static int ans[N];
  for (int i = 0; i < eq.size(); ++i) {
    static bool flag[N];
    int k = -1;
    for (int j = 0; j < eq.size(); ++j) if (!flag[j] && (k == -1 || tag[j] > tag[k])) k = j;
    flag[k] = true;
    for (int j = tag[k] + 1; j <= n; ++j) if (!ans[j]) ans[j] = 1; else break;
    int temp = eq[k][n + 1];
    for (int j = tag[k] + 1; j <= n; ++j) if (eq[k][j]) temp ^= (ans[j] == 1);
    ans[tag[k]] = temp ? 1 : 2;
  }
  for (int i = 1; i <= n; ++i) if (!ans[i]) ans[i] = 1;
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}