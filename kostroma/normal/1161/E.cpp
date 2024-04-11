#pragma comment(linker, "/STACK:512000000")
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
  cin >> t;
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

bool local = false;
vector<int> color;
int n;

void gen() {
  color.resize(n);
  for (int i = 0; i < n; ++i) {
    color[i] = rand() % 3;
  }
}

string get_res(vector<vector<int>> query) {
  if (query.empty()) {
    return "";
  }
  if (local) {
    set<int> qs;
    string res;
    for (auto item : query) {
      for (int x : item) {
        assert(!qs.count(x));
        qs.insert(x);
      }
      res += ((color[item[0]] == color[item[1]]) ? "1" : "0");
    }
    return res;
  } else {
    cout << "Q " << query.size();
    for (auto& item : query) {
      cout << " " << item[0] + 1 << " " << item[1] + 1;
    }
    cout << endl;
    string res;
    cin >> res;
    if (res == "-1") {
      exit(0);
    }
    return res;
  }
}

void print_ans(vector<vector<int>> ans) {
  assert(ans.size() == 3);
  assert(ans[0].size() + ans[1].size() + ans[2].size() == n);
  if (local) {
    vector<int> perm(3, -1);
    for (int x = 0; x < 3; ++x) {
      if (!ans[x].empty()) {
        perm[x] = color[ans[x][0]];
        for (int v : ans[x]) {
          assert(color[v] == perm[x]);
        }
      }
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        assert(perm[i] == -1 || perm[i] != perm[j]);
      }
    }
    cout << "ok" << endl;
  } else {
    cout << "A " << ans[0].size() << " " << ans[1].size() << " " << ans[2].size() << endl;
    for (int x = 0; x < 3; ++x) {
      for (int v : ans[x]) {
        cout << v + 1 << " ";
      }
      cout << endl;
    }
  }
}

void solve(__attribute__((unused)) bool read) {

  if (local) {
    n = rand() % 100000 + 1;
    gen();
  } else {
    cin >> n;
  }
  vector<int> same(n - 1);
  for (int w = 0; w < 2; ++w) {
    vector<vector<int>> q;
    for (int i = w; i + 1 < n; i += 2) {
      q.push_back({i, i + 1});
    }
    auto cur_res = get_res(q);
    for (int i = w, cnt = 0; i + 1 < n; i += 2, ++cnt) {
      same[i] = (cur_res[cnt] == '1');
    }
  }
  vector<pair<int, int>> segments;
  segments.push_back({0, 0});
  for (int i = 0; i + 1 < n; ++i) {
    if (same[i]) {
      ++segments.back().second;
    } else {
      segments.push_back({i + 1, i + 1});
    }
  }
  vector<int> same_shift(segments.size(), -1);
  for (int w = 0; w < 4; w += 2) {
    vector<vector<int>> q;
    for (int s = 0; s < 2; ++s) {
      for (int i = w + s; i + 2 < segments.size(); i += 4) {
        q.push_back({segments[i].first, segments[i + 2].first});
      }
    }
    auto cur_res = get_res(q);
    int cnt = 0;
    for (int s = 0; s < 2; ++s) {
      for (int i = w + s; i + 2 < segments.size(); i += 4) {
        same_shift[i] = (cur_res[cnt] == '1');
        ++cnt;
      }
    }
  }
  vector<int> res(segments.size());
  res[0] = 0;
  if (segments.size() > 1) {
    res[1] = 1;
  }
  for (int i = 2; i < segments.size(); ++i) {
    vector<char> used(3, false);
    used[res[i - 1]] = true;
    if (same_shift[i - 2]) {
      res[i] = res[i - 2];
      continue;
    }
    used[res[i - 2]] = true;
    for (int c = 0; c < 3; ++c) {
      if (!used[c]) {
        res[i] = c;
        break;
      }
    }
  }
  vector<vector<int>> ans(3);
  for (int i = 0; i < segments.size(); ++i) {
    for (int j = segments[i].first; j <= segments[i].second; ++j) {
      ans[res[i]].push_back(j);
    }
  }
  print_ans(ans);

}