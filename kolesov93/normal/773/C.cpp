#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 100111;
const int M = 60;
ll a[N];
ll powers[M];
int pows2[M], after_pows2[M];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  cin >> n;
  powers[0] = 1;
  for (int i = 1; i < M; ++i) {
    powers[i] = powers[i - 1] * static_cast<ll>(2);
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int pos = lower_bound(powers, powers + M, a[i]) - powers;
    if (a[i] == powers[pos]) {
      pows2[pos]++;
    } else {
      after_pows2[pos]++;
    }
  }

  bool have = false;
  for (int cnt = 1; cnt <= pows2[0]; ++cnt) {
    int opened = cnt;
    int have_less = 0;

    bool cool = true;
    for (int i = 0; i < M; ++i) {
      have_less += after_pows2[i];

      if (opened == 0 && have_less > 0) {
        cool = false;
        break;
      }

      if (pows2[i] >= opened) {
        have_less += pows2[i] - opened;
        continue;
      }

      int to_close = min(have_less, opened - pows2[i]);
      have_less -= to_close;
      opened = pows2[i];
    }

    if (cool) {
      have = true;
      printf("%d ", cnt);
    }
  }
  if (have) {
    printf("\n");
  } else {
    printf("-1\n");
  }


  return 0;
}