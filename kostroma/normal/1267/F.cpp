#pragma comment(linker, "/STACK:512000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#ifdef AIM
#include <sys/resource.h>
#endif
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
  string s = FILENAME;
//    assert(!s.empty());
  freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/home/alexandero/ClionProjects/cryptozoology/output.txt", "w", stdout);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif

#ifdef AIM
  const rlim_t kStackSize = 256 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif

  precalc();
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  int testNum = 1;
  while (t--) {
      //cout << "Case #" << testNum++ << ": ";
      solve(true);
  }
  cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
  cout.flush();
  auto end = clock();

  usleep(10000);
  print_stats(end - start);
  usleep(10000);
#endif

    return 0;
}

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
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {
}

//#define int li
//const int mod = 1000000007;

void solve(__attribute__((unused)) bool read) {
  int n[2], k[2];
  if (read) {
    cin >> n[0] >> n[1] >> k[0] >> k[1];
    if (k[0] >= n[1] || k[1] >= n[0]) {
      cout << "No\n";
      return;
    }
    cout << "Yes\n";
  } else {
    for (int i = 0; i < 2; ++i) {
      n[i] = rand() % (int)1e2 + 1;
    }
    k[0] = n[1] - 1;
    k[1] = n[0] - 1;
  }
  vector<vector<int>> vs(2);
  for (int i = 0; i < 2; ++i) {
    vs[i].resize(k[i]);
    for (int& x : vs[i]) {
      if (read) {
        cin >> x;
        --x;
      } else {
        x = rand() % n[i];
        if (i == 1) {
          x += n[0];
        }
      }
    }
    int new_v = (i == 0 ? 0 : n[0]);
    while (vs[i].size() + 1 < n[i ^ 1]) {
      vs[i].push_back(new_v);
    }
  }
  int N = n[0] + n[1];
  vector<int> deg(N, 1);
  for (int i = 0; i < 2; ++i) {
    for (int v : vs[i]) {
      ++deg[v];
    }
  }
  vector<set<int>> leaves(2);
  for (int i = 0; i < N; ++i) {
    if (deg[i] == 1) {
      int part = (i >= n[0]);
      leaves[part].insert(i);
    }
  }
  for (int i = 0; i < 2; ++i) {
    reverse(all(vs[i]));
  }
  vector<pair<int, int>> edges;
  for (int it = 0; it < N - 2; ++it) {
    auto add_leaf = [&] (int v, int pred) {
      --deg[v];
      edges.emplace_back(pred, v);
      if (deg[v] != 1) {
        return;
      }
      int part = (v >= n[0]);
      leaves[part].insert(v);
    };
    if (!leaves[0].empty()) {
      int v = *leaves[0].begin();
      leaves[0].erase(v);
      assert(!vs[1].empty());
      --deg[v];
      add_leaf(vs[1].back(), v);
      vs[1].pop_back();
    } else {
      assert(!leaves[1].empty());
      int v = *leaves[1].begin();
      leaves[1].erase(v);
      assert(!vs[0].empty());
      --deg[v];
      add_leaf(vs[0].back(), v);
      vs[0].pop_back();
    }
  }
  assert(leaves[0].size() == 1 && leaves[1].size() == 1);
  edges.emplace_back(*leaves[0].begin(), *leaves[1].begin());

  /*vector<set<int>> gg(N);
  for (auto item : edges) {
    gg[item.first].insert(item.second);
    gg[item.second].insert(item.first);
  }
  vector<int> prufer;
  while (prufer.size() < N - 2) {
    for (int i = 0; i < N; ++i) {
      if (gg[i].size() == 1) {
        int to = *gg[i].begin();
        cout << "i: " << i << " to: " << to << endl;
        prufer.push_back(to);
        gg[i].clear();
        gg[to].erase(i);
        break;
      }
    }
  }
  for (int x : prufer) {
    cout << x + 1 << " ";
  }
  cout << endl;*/

  if (read) {
    for (auto item : edges) {
      cout << item.first + 1 << " " << item.second + 1 << endl;
    }
  } else {
    cout << "ok\n";
  }

}