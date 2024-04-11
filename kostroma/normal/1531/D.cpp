#pragma comment(linker, "/STACK:512000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <memory>
#include <chrono>
#include <cassert>
#include <random>
#include <queue>
#include <set>
#include <map>
#include <array>

using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    cout.precision(20);
    cout << fixed;
    //cin >> t;
    precalc();
    int test_num = 1;
    while (t--) {
      //cout << "Case #" << test_num++ << ": ";
      solve(true);
    }
    cout.flush();

#ifdef AIM1
    while (true) {
    solve(false);
  }
#endif

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& vec) {
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

void precalc() {

}

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

struct Node {
  array<bool, 2> locked;
  array<string, 2> color;
  Node() {
    locked[false] = false;
    locked[true] = true;
    color[false] = "blue";
    color[true] = "";
  }
};

Node merge(const Node& q, const Node& w) {
  Node res = {};
  for (int locked = 0; locked < 2; ++locked) {
    int middle_locked = q.locked[locked];
    res.locked[locked] = w.locked[middle_locked];
    res.color[locked] = (w.color[middle_locked].empty() ? q.color[locked] : w.color[middle_locked]);
  }
  return res;
}

struct SegTree {
  int shift;
  vector<Node> tree;

  Node get_vertex(const string& s) {
    Node cur_node = {};
    if (s == "lock") {
      for (int locked = 0; locked < 2; ++locked) {
        cur_node.locked[locked] = true;
        cur_node.color[locked] = "";
      }
    } else if (s == "unlock") {
      for (int locked = 0; locked < 2; ++locked) {
        cur_node.locked[locked] = false;
        cur_node.color[locked] = "";
      }
    } else {
      for (int locked = 0; locked < 2; ++locked) {
        cur_node.locked[locked] = locked;
      }
      cur_node.color[0] = s;
      cur_node.color[1] = "";
    }
    return cur_node;
  }

  SegTree(vector<string>& data) {
    shift = 1;
    while (shift < data.size()) {
      shift *= 2;
    }
    tree.assign(2 * shift, Node());
    for (int i = 0; i < data.size(); ++i) {
      tree[i + shift] = get_vertex(data[i]);
    }
    for (int i = shift - 1; i > 0; --i) {
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
  }
  void update(int v, const string& s) {
    v += shift;
    tree[v] = get_vertex(s);
    v /= 2;
    while (v > 0) {
      tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
      v /= 2;
    }
  }
  vector<int> vs;
  string get_res(int n) {
    int l = shift, r = shift + n;
    vs.clear();
    while (l < r) {
      if (l + 1 == r) {
        vs.push_back(l);
        break;
      }
      if (r & 1) {
        --r;
        vs.push_back(r);
        continue;
      }
      l /= 2;
      r /= 2;
    }
    Node res = {};
    reverse(all(vs));
    for (int v : vs) {
      res = merge(res, tree[v]);
      //cout << v << " " << res.color[0] << endl;
    }
    return res.color[0];
  }
};

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<string> data(n);
  for (auto& s : data) {
    cin >> s;
  }
  SegTree tree(data);
  cout << tree.get_res(n) << "\n";
  int Q;
  cin >> Q;
  while (Q--) {
    int pos;
    string s;
    cin >> pos >> s;
    tree.update(pos - 1, s);
    cout << tree.get_res(n) << "\n";
  }

}