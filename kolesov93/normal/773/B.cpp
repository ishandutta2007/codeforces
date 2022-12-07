#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int a[5], b[5];
int cnt[5];
int status[5]; // 1 - max, 2 - min, 0 - none
int people = 0;
int ds[] = {32, 16, 8, 4, 2, 1};
int prize[] = {3000, 2500, 2000, 1500, 1000, 500};

int main() {
  int n;
  cin >> n;
  bool have = false;
  for (int i = 0; i < 5; ++i) {
    cin >> a[i];
    if (a[i] != -1) {
      cnt[i]++;
      have = true;
    }
  }
  if (have) people++;
  have = false;
  for (int i = 0; i < 5; ++i) {
    cin >> b[i];
    if (b[i] != -1) {
      cnt[i]++;
      have = true;
    }
  }
  if (have) people++;

  for (int i = 3; i <= n; ++i) {
    have = false;
    for (int j = 0; j < 5; ++j) {
      int x;
      cin >> x;
      if (x != -1) {
        cnt[j]++;
        have = true;
      }
    }
    if (have) people++;
  }

  int best_score = 0;
  for (int i = 0; i < 5; ++i) {
    if (a[i] != -1) {
      if (b[i] == -1) {
        status[i] = 1;
        best_score += 3000 - a[i] * 3000 / 250;
      } else {
        if (a[i] < b[i]) {
          status[i] = 1;
          best_score += 3000 - a[i] * 3000 / 250;
          best_score -= 3000 - b[i] * 3000 / 250;
        } else if (a[i] > b[i]) {
          status[i] = 2;
          best_score += 500 - a[i] * 500 / 250;
          best_score -= 500 - b[i] * 500 / 250;
        }
      }
    } else {
      if (b[i] != -1) {
        status[i] = 0;
        best_score -= 500 - b[i] * 500 / 250;
      }
    }
  }

  for (int answer = 0; answer < (people * 5000); ++answer) {
    int score = 0;
    int all = people + answer;
    for (int task = 0; task < 5; ++task) {
      int solved = cnt[task];
      if (status[task] == 2) {
        solved = cnt[task] + answer;
      }

      int cur_prize = 0;
      for (int k = 0; k < 6; ++k) {
        if (solved * ds[k] <= all) {
          cur_prize = prize[k];
          break;
        }
      }

      if (a[task] != -1) score += cur_prize - a[task] * cur_prize / 250;
      if (b[task] != -1) score -= cur_prize - b[task] * cur_prize / 250;
    }
    if (score > 0) {
      cout << answer << endl;
      return 0;
    }
  }
  puts("-1");

  return 0;
}