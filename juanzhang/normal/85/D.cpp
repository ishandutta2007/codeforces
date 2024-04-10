#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 1e5 + 10;
int q;

int bsz;
int tot, data[maxn];

struct Querys {
  int op, x;
} Q[maxn];

bool vis[maxn];
int bl[maxn], cnt[1010];
ll sum[1010][5];

void solve() {
  cin >> q;
  char str[5];
  rep(i, 1, q) {
    scanf("%s", str);
    Q[i].op = *str == 'a' ? 1 : *str == 'd' ? 2 : 3;
    if (Q[i].op != 3) {
      scanf("%d", &Q[i].x), data[++tot] = Q[i].x;
    }
  }
  sort(data + 1, data + tot + 1);
  tot = unique(data + 1, data + tot + 1) - data - 1;
  bsz = sqrt(tot);
//  printf("@%d\n",bsz);
  rep(i, 1, tot) bl[i] = (i - 1) / bsz + 1;
  rep(T, 1, q) {
    if (Q[T].op == 1) {
      int pos = lower_bound(data + 1, data + tot + 1, Q[T].x) - data;
      vis[pos] = 1, cnt[bl[pos]]++;
      rep(i, 0, 4) sum[bl[pos]][i] = 0;
      int cur = 1;
      rep(i, (bl[pos] - 1) * bsz + 1, min(tot, bl[pos] * bsz)) if (vis[i]) {
        sum[bl[pos]][cur] += data[i], cur = (cur + 1) % 5;
      }
    } else if (Q[T].op == 2) {
      int pos = lower_bound(data + 1, data + tot + 1, Q[T].x) - data;
      vis[pos] = 0, cnt[bl[pos]]--;
      rep(i, 0, 4) sum[bl[pos]][i] = 0;
      int cur = 1;
      rep(i, (bl[pos] - 1) * bsz + 1, min(tot, bl[pos] * bsz)) if (vis[i]) {
        sum[bl[pos]][cur] += data[i], cur = (cur + 1) % 5;
      }
    } else {
      ll res = 0;
      int now = 0;
      rep(i, 1, bl[tot]) {
        res += sum[i][(3 - now%5 + 5) % 5];
//        printf("#(%d %d)\n",i,(3-now%5+5)%5);
        now += cnt[i];
      }
      printf("%I64d\n", res);
    }
//    puts("!");
//    rep(i,1,tot)if(vis[i]){
//      printf("%d ",data[i]);
//    }
//    rep(i,1,bl[tot]){
//      putchar('#');
//      rep(j,0,4){
//        printf("%d ",sum[i][j]);
//      }
//      puts("");
//    }
//    puts("");
  }
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}