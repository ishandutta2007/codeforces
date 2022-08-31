#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <limits>

using namespace std;


// (winner, loser)
pair<int, int> compare(int a, int b) {
  printf("? %d %d\n", a + 1, b + 1);
  fflush(stdout);
  char buffer[3];
  scanf("%s", buffer);
  if (buffer[0] == '<') return make_pair(b, a);
  return make_pair(a, b);
}

// returns the strongest(highest) 3 players.
// If this returns {a,b,c}, then comparison was made for {a,b}.
vector<int> Solve3(vector<int> players) {
  int a, b, c, d, e, f;
  tie(a, d) = compare(players[0], players[3]);
  tie(b, e) = compare(players[1], players[4]);
  tie(c, f) = compare(players[2], players[5]);
  int l0, l1, l2;
  tie(l0, l1) = compare(d, e);
  tie(l1, l2) = compare(l1, f);
  tie(l0, l1) = compare(l0, l1);
  int w0, w1, w2;

  if (l0 == d) w0 = a;
  if (l0 == e) w0 = b;
  if (l0 == f) w0 = c;
  if (l1 == d) w1 = a;
  if (l1 == e) w1 = b;
  if (l1 == f) w1 = c;
  if (l2 == d) w2 = a;
  if (l2 == e) w2 = b;
  if (l2 == f) w2 = c;

  if (compare(l1, w2) == make_pair(l1, w2)) return{ l0, w0, w1 };
  int x, y;
  tie(x, y) = compare(w1, w2);
  if (compare(y, l0) == make_pair(y, l0)) return{ y, x, w0 };
  return{ l0, w0, x };
}

vector<int> solve(vector<int> players) {
  int n = players.size() / 2;
  vector<int> losers, winners;
  for (int i = 0; i < n; i++) {
    int w, l;
    tie(w,l) = compare(players[i], players[i + n]);
    losers.emplace_back(l);
    winners.emplace_back(w);
  }
  // strongest to 0th
  for (int i = 0; i < n; i++) {
    int low = 0, high = i - 1;
    int pos = i;
    while (low <= high) {
      int mid = (low + high) / 2;
      int w, l;
      tie(w, l) = compare(losers[i], losers[mid]);
      if (w == losers[i]) {
        pos = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    rotate(losers.begin() + pos, losers.begin() + i, losers.begin() + i + 1);
    rotate(winners.begin() + pos, winners.begin() + i, winners.begin() + i + 1);
  }
  for (int i = 1; i < n; i++) {
    int low = 1, high = i - 1;
    int pos = i;
    while (low <= high) {
      int mid = (low + high) / 2;
      int w, l;
      tie(w, l) = compare(winners[i], winners[mid]);
      if (w == winners[i]) {
        pos = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    rotate(winners.begin() + pos, winners.begin() + i, winners.begin() + i + 1);
  }
  {
    int w, l;
    tie(w, l) = compare(losers[0], winners.back());
    if (l == losers[0]) return winners;
  }
  int discarded = 0;
  int a = n - 1, b = n - 1;
  while (discarded < n) {
    if (a == 0) break;
    int w, l;
    if (winners[a] - losers[b] == n || winners[a] - losers[b] == -n) {
      w = winners[a];
      l = losers[b];
    } else {
      tie(w, l) = compare(winners[a], losers[b]);
    }
    if (w == winners[a]) {
      discarded++;
      b--;
    } else {
      discarded++;
      a--;
    }
  }
  while (discarded < n) {
    if (b > 0) {
      discarded++;
      b--;
    }
  }
  vector<int> ans;
  for (int i = 0; i <= a; i++) ans.push_back(winners[i]);
  for (int i = 0; i <= b; i++) ans.push_back(losers[i]);
  return ans;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T-- > 0) {
    int n;
    scanf("%d", &n);
    vector<int> players(2*n);
    iota(players.begin(), players.end(), 0);
    vector<int> ans;
    if (n == 3) {
      ans = Solve3(players);
    } else {
      ans = solve(players);
    }
    printf("!\n");
    fflush(stdout);
  }
  return 0;
}