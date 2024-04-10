#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 110;

int n;
char s[N];
int cnt[26];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i)
      ++cnt[s[i] - 'a'];
    bool flag = false;
    for (int i = 2; i <= n; ++i)
      flag |= abs(s[i] - s[i - 1]) == 1;
    if (!flag) {
      puts(s + 1);
      continue;
    }
    int a = -1, b = -1;
    for (int i = 0; i < 26; i += 2) {
      for (int j = 1; j < 26; j += 2) {
        if (cnt[i] && cnt[j] && abs(i - j) != 1) {
          a = i;
          b = j;
        }
      }
    }
    if (a == -1)
      puts("No answer");
    else {
      --cnt[a];
      --cnt[b];
      for (int i = 0; i < 26; i += 2)
        while (cnt[i]--)
          putchar(i + 'a');
      putchar(a + 'a');
      putchar(b + 'a');
      for (int i = 1; i < 26; i += 2)
        while (cnt[i]--)
          putchar(i + 'a');
      putchar('\n');
    }
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}