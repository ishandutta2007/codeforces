#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m";
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

using LL = long long;
using PII = std::pair<int, int>;

class ACAutomaton {
 public:
  std::vector<std::string> strs;
  ACAutomaton(): t(1), strs() {}
  void ins(std::string s) {
    strs.push_back(s);
    int o = 0;
    for (char c : s) {
      if (!t[o].s[c - 'a']) {
        t[o].s[c - 'a'] = t.size();
        t.push_back(Node());
      }
      o = t[o].s[c - 'a'];
    }
    t[o].cnt++;
  }
  void build() {
    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int o = q.front(); q.pop();
      if (t[o].fa == o) t[o].fa = 0;
      if (t[o].fa) {
        t[o].cnt += t[t[o].fa].cnt;
      }
      for (int i = 0; i < 26; i++) {
        if (t[o].s[i]) {
          q.push(t[o].s[i]);
          t[t[o].s[i]].fa = t[t[o].fa].s[i];
        } else {
          t[o].s[i] = t[t[o].fa].s[i];
        }
      }        
    }
  }
  LL ask(std::string s) const {
    int o = 0;
    LL ans = 0;
    for (char c : s) {
      o = t[o].s[c - 'a'];
      ans += t[o].cnt;
    }
    return ans;
  }
 private:
  struct Node {
    std::array<int, 26> s;
    int cnt, fa;
    Node(): cnt(0), fa(0) {
      for (int i = 0; i < 26; i++) s[i] = 0;
    }
  };
  std::vector<Node> t;
};
class Solver {
 public:
  void add(std::string s) {
    ACAutomaton now;
    now.ins(s);
    while (!a.empty() && a.back().strs.size() == now.strs.size()) {
      for (const auto &str : a.back().strs) now.ins(str);
      a.pop_back();
    }
    now.build();
    a.push_back(now);
  }
  LL ask(std::string s) {
    LL ans = 0;
    for (const auto &x : a) ans += x.ask(s);
    return ans;
  }
 private:
  std::vector<ACAutomaton> a;
} t1, t2;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int opt;
    std::string s;
    std::cin >> opt >> s;
    if (opt == 1) {
      t1.add(s);
    } else if (opt == 2) {
      t2.add(s);
    } else {
      std::cout << t1.ask(s) - t2.ask(s) << std::endl;
    }
  }
  return 0;
}