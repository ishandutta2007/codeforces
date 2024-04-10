#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#else
#define dbg(x) (x)
#endif

int N, T, K;

int askn0(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ret;
    cin >> ret;
    return (r - l + 1) - ret;
}

void answer(int x) {
    cout << "! " << x << endl;
}

int main() {
    // cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int K;
    cin >> N >> T >> K;

    constexpr int bs = 16;
    vector<int> batch;
    vector<int> Ls, Rs;
    for (int l = 1; l <= N; l += bs) {
        int r = min(N, l + bs - 1);
        int n0 = askn0(l, r);
        batch.push_back(n0);
        Ls.push_back(l);
        Rs.push_back(r);
    }

    REP(t, T) {
        if (t) cin >> K;
        int b = 0;
        int n0 = 0;
        while (n0 < K) n0 += batch[b++];
        b--;
        n0 -= batch[b];
        int y = K - n0;
        int lo = Ls[b] - 1, hi = Rs[b];
        while (hi - lo > 1) {
            const int c = (lo + hi) / 2;
            int n0 = askn0(Ls[b], c);
            (n0 >= y ? hi : lo) = c;
        }
        answer(hi);
        batch[b]--;
    }
}