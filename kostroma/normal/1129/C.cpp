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
const int mod = 1000000007;

struct Node {
  int to[2];
  int min_end;
  Node() {
    to[0] = to[1] = -1;
    min_end = 0;
  }
};

vector<Node> nodes;

const int C = 3010;
//int first_start[C][C];
int dp[C][C];

void add(int& cur, int val) {
  cur = (cur + val) % mod;
}

void solve(__attribute__((unused)) bool read) {
  nodes.push_back(Node());
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<char> cant(n, false);
  set<string> no_way;
  no_way.insert("0011");
  no_way.insert("0101");
  no_way.insert("1110");
  no_way.insert("1111");
  for (int i = 0; i + 4 <= n; ++i) {
    string cur;
    for (int j = i; j < i + 4; ++j) {
      cur += (char)('0' + a[j]);
    }
    if (no_way.count(cur)) {
      cant[i] = true;
    }
  }
  int res = 0;
  for (int pref = 0; pref < n; ++pref) {
    dp[pref][pref] = 1;
    int v = 0;
    for (int j = pref; j >= 0; --j) {
      if (nodes[v].to[a[j]] == -1) {
        nodes[v].to[a[j]] = nodes.size();
        nodes.push_back(Node());
        nodes.back().min_end = j;
        dp[j][pref + 1] = 0;
        for (int len = 1; len <= 4 && len <= pref - j + 1; ++len) {
          if (len == 4 && cant[pref - len + 1]) {
            continue;
          }
          add(dp[j][pref + 1], dp[j][pref + 1 - len]);
        }
        add(res, dp[j][pref + 1]);
      }
      v = nodes[v].to[a[j]];
      int l = nodes[v].min_end;
      int r = l + (pref + 1 - j);
      dp[j][pref + 1] = dp[l][r];
    }
    cout << res << "\n";
  }
}