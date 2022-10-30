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
const int N = 1e6 + 77, maxn = 200000, inf = 1e9 + 77, px[7] = {0, 0, -1, 1}, py[7] = {-1, 1, 0, 0};

int a[N], ans[N];


int main() {
  ios_base::sync_with_stdio(0);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, q;
  ll nech = 0;
  ll ch = 0;
  ll sdvig = 0;
  int kd = 0;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      sdvig += x;
      nech += x;
      ch += x;
    } else {
      ll sdvig1 = abs(sdvig);
      if (sdvig1 % 2 == 0) {
        if (!kd) {
          nech++;
          ch--;
          kd = 1;
        } else {
          nech--;
          ch++;
          kd = 0;
        }
      } else {
        if (!kd) {
          nech--;
          ch++;
          kd = 1;
        } else {
          nech++;
          ch--;
          kd = 0;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      int pos = (1LL * i + nech + 2 * n) % n;
      if (pos < 0) {
        pos += n;
      }
      ans[pos] = i + 1;
    } else {
      int pos = (1LL * i + ch + 2 * n) % n;
      if (pos < 0) {
        pos += n;
      }
      ans[pos] = i + 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      printf(" ");
    }
    printf("%d", ans[i]);
  }
  printf("\n");
}