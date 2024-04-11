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

#define int li
//const int mod = 1000000007;

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;

  set<pair<int, int>> suf_mins;
  int start_value = 0;
  int suf_add = 0;
  set<pair<int, pair<int, int>>> events;
  int b_add = 0, s_add = 0;

  auto get_event_time = [&] (pair<int, int> prev, pair<int, int> cur) {
    int step = cur.first - prev.first;
    int diff = prev.second - cur.second;
    return (diff - 1) / step + 1;
  };

  auto suf_min_push_back = [&] (int pos, int value) {
    int decreased_value = value - b_add - s_add * pos;
    if (!suf_mins.empty()) {
      auto item = *(--suf_mins.end());
      int new_time = get_event_time(item, {pos, decreased_value});
      //cout << pos << " " << new_time << endl;
      events.insert({new_time, {pos, decreased_value}});
    }
    suf_mins.insert({pos, decreased_value});
  };

  auto erase_pair = [&] (pair<int, int> item) {
    auto it = suf_mins.find(item);
    assert(it != suf_mins.end());
    auto next_it = next(it);
    auto prev_it = prev(it);
    if (next_it != suf_mins.end()) {
      events.erase({get_event_time(*it, *next_it), *next_it});
      int new_time = get_event_time(*prev_it, *next_it);
      events.insert({new_time, *next_it});
    }
    suf_mins.erase(it);
  };

  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int k;
      cin >> k;
      n += k;
      suf_mins.clear();
      events.clear();
      b_add = 0;
      s_add = 0;
      start_value = 0;
      if (suf_add > 0) {
        suf_min_push_back(n, 0);
      }
    } else if (type == 2) {
      int k;
      cin >> k;
      if (suf_add == 0) {
        suf_min_push_back(n, 0);
      }
      suf_add += k;
    } else {
      int b, s;
      cin >> b >> s;
      start_value += b;
      b_add += b;
      s_add += s;
      while (!events.empty()) {
        auto ev = *events.begin();
        if (ev.first > s_add) {
          break;
        }
        events.erase(events.begin());
        erase_pair(ev.second);
      }
      n += suf_add;
      suf_add = 0;
    }

    if (!suf_mins.empty()) {
      auto& cur = *(--suf_mins.end());
      int cur_value = cur.second + b_add + s_add * cur.first;
      if (cur_value < start_value) {
        cout << cur.first + 1 << " " << cur_value << "\n";
        continue;
      }
    }
    cout << 1 << " " << start_value << "\n";

  }
}