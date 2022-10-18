#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<uint64_t, pair<int, int>, custom_hash> node;
unordered_map<uint64_t, vector<int>, custom_hash> comp;

void add_edge(int a, int b, int x) {
  if (!node.count(a)) node[a] = {a, 0}, comp[a] = {a};
  if (!node.count(b)) node[b] = {b, 0}, comp[b] = {b};

  auto pa = node[a];
  auto pb = node[b];

  int c = pa.first, d = pb.first;

  if (c == d) return;

  if (comp[c].size() < comp[d].size()) swap(c, d), swap(a, b), swap(pa, pb);

  int diff = pa.second ^ x ^ pb.second;

  auto& compc = comp[c];
  auto& compd = comp[d];

  int ptr = compc.size();
  compc.resize(compc.size() + compd.size());
  for (int y: comp[d]) {
    auto cur = node[y];
    node[y] = {c, cur.second ^ diff};
    compc[ptr++] = y;
  }
  comp[d].clear();
}

int query(int a, int b) {
  if (node.count(a) && node.count(b)) {
    auto pa = node[a];
    auto pb = node[b];
    if (pa.first == pb.first) return pa.second ^ pb.second;
  }
  return -1;
}

int main(void) {
  ios_base::sync_with_stdio(false);

  int Q;
  cin >> Q;
  int last = 0;

  while (Q--) {
    int t;
    cin >> t;

    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l ^= last, r ^= last, x ^= last;

      if (l > r) swap(l, r);
      add_edge(l, r + 1, x);
    } else {
      int l, r;
      cin >> l >> r;

      l ^= last, r ^= last;
      if (l > r) swap(l, r);

      last = query(l, r + 1);
      cout << last << "\n";

      if (last == -1) last = 1;
    }
  }
  return 0;
}