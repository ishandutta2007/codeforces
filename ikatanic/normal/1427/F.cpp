#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

const int MAX = 1202;

struct Move {
  int a, b, c;
  int who;
};

int n;
int a[MAX];
Move moves[MAX];
vector<int> E[MAX];
int cnt;

int dfs(int& s) {
  assert(s < n);

  vector<int> p;
  p.push_back(s);
  int k = a[s++];
  int x = cnt++;

  while (p.size() < 3) {
    assert(s < n);
    if (a[s] == k) {
      p.push_back(s);
      s++;
    } else {
      int y = dfs(s);
      E[x].push_back(y);
    }
  }

  moves[x] = {p[0], p[1], p[2], k};
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> n;
  n *= 6;

  for (int i = 0; i < n / 2; ++i) {
    int x;
    cin >> x;
    --x;
    a[x] = 1;
  }

  cnt = 1;
  int ptr = 0;

  while (ptr < n) {
    int y = dfs(ptr);
    E[0].push_back(y);
  }

  vector<int> can = E[0];
  vector<Move> ret;
  for (int i = 0; i < n / 3; ++i) {
    int k = i % 2;

    int x = -1;
    for (int y : can) {
      if (moves[y].who == k && E[y].size()) x = y;
    }

    if (x == -1) {
      for (int y : can) {
        if (moves[y].who == k) x = y;
      }
    }
    assert(x != -1);

    ret.push_back(moves[x]);
    can.erase(find(can.begin(), can.end(), x));
    for (int y : E[x]) can.push_back(y);
  }

  reverse(ret.begin(), ret.end());
  for (auto& v : ret) {
    v.a++, v.b++, v.c++;
    cout << v.a << ' ' << v.b << ' ' << v.c << '\n';
  }

  return 0;
}