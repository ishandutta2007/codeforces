#include <bits/stdc++.h>
using namespace std;

constexpr int kMaxQ = 300000;
constexpr int kMaxLogQ = 20;

int Q;
int a[kMaxQ + 1], c[kMaxQ + 1];
int parent[kMaxLogQ][kMaxQ + 1];

int main() {
  scanf("%d %d %d", &Q, &a[0], &c[0]);
  for (int i = 0; i < kMaxLogQ; ++i) {
    parent[i][0] = 0;
  }
  for (int q = 1; q <= Q; ++q) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d %d %d", &parent[0][q], &a[q], &c[q]);
      for (int i = 1; i < kMaxLogQ; ++i) {
        parent[i][q] = parent[i - 1][parent[i - 1][q]];
      }
    } else {
      int v, w;
      scanf("%d %d", &v, &w);
      pair<int, long long> answer = make_pair(0, 0);
      while (w > 0 && a[v] > 0) {
        int u = v;
        for (int i = kMaxLogQ - 1; i >= 0; --i) {
          if (a[parent[i][u]] > 0) {
            u = parent[i][u];
          }
        }
        int take = min(w, a[u]);
        a[u] -= take;
        w -= take;
        answer.first += take;
        answer.second += (long long)take * c[u];
      }
      printf("%d %lld\n", answer.first, answer.second);
      fflush(stdout);
    }
  }
}