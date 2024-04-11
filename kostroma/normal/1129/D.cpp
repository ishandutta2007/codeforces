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
const int mod = 998244353;

void add(int& cur, int val) {
  cur += val;
  if (cur >= mod) {
    cur -= mod;
  }
  if (cur < 0) {
    cur += mod;
  }
}

struct Block {
  int l, r;
  int border;
  vector<int> dp;
  vector<int> close_sums;
  vector<int> score;
  int shift_sum;
  int k;
  int good_sum = 0;
  void init(int L, int R, int tre, int K) {
    border = tre;
    l = L;
    r = R;
    k = K;
    dp.assign(r - l, 0);
    score.assign(r - l, 0);
    shift_sum = 0;
    close_sums.assign(2 * border + 1, 0);
  }
  void perform_shift() {
    close_sums.assign(2 * border + 1, 0);
    for (int i = l; i < r; ++i) {
      score[i - l] += shift_sum;
    }
    shift_sum = 0;
    good_sum = 0;
  }
  void restore() {
    for (int i = l; i < r; ++i) {
      if (score[i - l] <= k) {
        add(good_sum, dp[i - l]);
      }
      if (abs(score[i - l] - k) < border) {
        add(close_sums[border + score[i - l] - k], dp[i - l]);
      }
    }
  }
  void simple_shift(int val) {
    if (val == 1) {
      add(good_sum, -close_sums[border - shift_sum]);
    } else {
      add(good_sum, close_sums[border - shift_sum + 1]);
    }
    shift_sum += val;
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, k;
  //read = false;
  if (read) {
    cin >> n >> k;
  } else {
    n = rand() % 100 + 1;
    k = rand() % n + 1;
    cout << "test " << n << " " << k << endl;
  }
  vector<int> a(n);
  vector<int> prev_same(n, -1);
  vector<int> last_pos(n, -1);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
      --a[i];
    } else {
      a[i] = rand() % n;
      cout << a[i] + 1 << " \n"[i + 1 == n];
    }
    prev_same[i] = last_pos[a[i]];
    last_pos[a[i]] = i;
  }
  int block_size = max((int)1, (int)sqrt(n));
  int n_blocks = n / block_size + 1;
  vector<Block> blocks(n_blocks);

  auto perform_addition = [&](int l, int r, int cur_block, int val) {
    int l_b = l / block_size, r_b = min(r / block_size, cur_block - 1);
    for (int pos = max(blocks[cur_block].l, l); pos < r; ++pos) {
      blocks[cur_block].score[pos - blocks[cur_block].l] += val;
    }
    if (l_b > r_b) {
      return;
    }
    blocks[l_b].perform_shift();
    for (int pos = l; pos < r && pos < blocks[l_b].r; ++pos) {
      blocks[l_b].score[pos - blocks[l_b].l] += val;
    }
    blocks[l_b].restore();
    if (l_b == r_b) {
      return;
    }
    blocks[r_b].perform_shift();
    for (int pos = blocks[r_b].l; pos < r && pos < blocks[r_b].r; ++pos) {
      blocks[r_b].score[pos - blocks[r_b].l] += val;
    }
    blocks[r_b].restore();
    for (int i = l_b + 1; i < r_b; ++i) {
      blocks[i].simple_shift(val);
    }
  };

  int ans = 0;
  for (int i = 0; i < n_blocks; ++i) {
    int l = i * block_size, r = min((i + 1) * block_size, n + 1);
    auto& bl = blocks[i];
    bl.init(l, r, block_size + 3, k);
    for (int j = 0; j < i; ++j) {
      blocks[j].perform_shift();
      blocks[j].restore();
    }
    for (int pos = l; pos < r; ++pos) {
      if (pos == 0) {
        bl.dp[0] = 1;
        continue;
      }
      int prev_pos = prev_same[pos - 1];
      {
        perform_addition(prev_pos + 1, pos, i, 1);
      }
      if (prev_pos != -1) {
        perform_addition(prev_same[prev_pos] + 1, prev_pos + 1, i, -1);
      }
      int cur_dp = 0;
      for (int j = 0; j < i; ++j) {
        add(cur_dp, blocks[j].good_sum);
        //cout << "add to " << pos << " " << j << " " << blocks[j].good_sum << endl;
      }
      for (int j = l; j < pos; ++j) {
        if (blocks[i].score[j - l] <= k) {
          add(cur_dp, blocks[i].dp[j - l]);
        }
      }
      blocks[i].dp[pos - l] = cur_dp;
      ans = cur_dp;
      //cout << pos << " " << cur_dp << endl;
    }
  }
  cout << ans << "\n";

  if (false) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        map<int, int> cnt;
        for (int r = j; r < i; ++r) {
          cnt[a[r]]++;
        }
        int cur = 0;
        for (auto item : cnt) {
          if (item.second == 1) {
            ++cur;
          }
        }
        if (cur <= k) {
          add(dp[i], dp[j]);
        }
      }
    }
    if (dp[n] != ans) {
      cout << "FOUND ans: " << ans << " stupid: " << dp[n] << endl;
      for (int i = 0; i <= n; ++i) {
        cout << "stup " << i << " " << dp[i] << endl;
      }
      exit(0);
    }
  }

}