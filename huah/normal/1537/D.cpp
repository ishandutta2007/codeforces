#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5, mod = 1e9 + 7;
int n, sg[N];
bool vis[N];
int main() {
  // freopen("1.in", "r", stdin);
  // for (int i = 3; i <= 100; i++) {
  //   for (int j = 2; j < i; j++)
  //     if (i % j == 0) {
  //       vis[sg[i - j]] = true;
  //     }
  //   while (vis[sg[i]]) sg[i]++;
  //   for (int j = 2; j < i; j++)
  //     if (i % j == 0) {
  //       vis[sg[i - j]] = false;
  //     }
  //   if (i % 2 == 1) assert(sg[i] == 0);
  // }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    if (n & 1)
      printf("Bob\n");
    else {
      int tot = 0;
      while (n % 2 == 0) n /= 2, tot++;
      if (n != 1)
        printf("Alice\n");
      else if (tot & 1)
        printf("Bob\n");
      else
        printf("Alice\n");
    }
  }
}
/*
4
1
4
12
69

Bob
Alice
Alice
Bob
*/