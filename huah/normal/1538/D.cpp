#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5;
int a, b, k;
map<int, int> vis;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &a, &b, &k);
    if (a > b) swap(a, b);
    int l = a == b ? 2 : 1;
    vector<pair<int, int> > v1, v2;
    for (int i = 2; i * i <= a; i++)
      if (a % i == 0) {
        int sum = 0;
        while (a % i == 0) a /= i, sum++;
        v1.push_back(mp(i, sum));
      }
    if (a > 1) v1.push_back(mp(a, 1));
    for (int i = 2; i * i <= b; i++)
      if (b % i == 0) {
        int sum = 0;
        while (b % i == 0) b /= i, sum++;
        v2.push_back(mp(i, sum));
      }
    if (b > 1) v2.push_back(mp(b, 1));
    int r = 0;
    vis.clear();
    for (int i = 0; i < v1.size(); i++) r += v1[i].second;
    for (int i = 0; i < v2.size(); i++)
      r += v2[i].second, vis[v2[i].first] = v2[i].second;
    for (int i = 0; i < v1.size(); i++) {
      if (!vis.count(v1[i].first) || vis[v1[i].first] < v1[i].second) {
        l = 2;
        break;
      }
    }
    printf(k >= l && k <= r ? "YES\n" : "NO\n");
  }
}