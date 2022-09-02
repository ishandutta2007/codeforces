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
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#else
#define dbg(x) (x)
#endif

template <typename T> std::vector<std::vector<T>> trans(std::vector<std::vector<T>> v) {
    int H = v.size(), W = v[0].size();
    std::vector<std::vector<T>> ret(W, std::vector<T>(H));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) ret[j][i] = v[i][j];
    }
    return ret;
}


int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    cin >> S;

    vector left(H, vector<int>(W, -1));
    vector right(H, vector<int>(W, W));
    vector up(H, vector<int>(W, -1));
    vector down(H, vector<int>(W, H));
    FOR(i, 1, H) REP(j, W) {
        up[i][j] = up[i - 1][j];
        if (S[i - 1][j] == '1') up[i][j] = i - 1;
    }
    REP(i, H) FOR(j, 1, W) {
        left[i][j] = left[i][j - 1];
        if (S[i][j - 1] == '1') left[i][j] = j - 1;
    }
    IREP(i, H - 1) REP(j, W) {
        down[i][j] = down[i + 1][j];
        if (S[i + 1][j] == '1') down[i][j] = i + 1;
    }
    REP(i, H) IREP(j, W - 1) {
        right[i][j] = right[i][j + 1];
        if (S[i][j + 1] == '1') right[i][j] = j + 1;
    }
    vector<vector<int>> mat[2][2];
    mat[0][0] = trans(left), mat[0][1] = trans(right);
    mat[1][0] = up, mat[1][1] = down;
    lint ret = 0;

    auto divconq2d = [&](int mode, int xlo, int xhi, int ylo, int yhi) -> void {
        const int cx = (xlo + xhi) / 2;
        FOR(L, ylo, yhi) {
            vector<int> vup(K + 2, xlo - 1), vdown(K + 2, xhi);
            vup[0] = cx - 1;
            vdown[0] = cx;
            FOR(i, L, yhi) {
                int x = mat[mode][0][cx][i];
                int j = 0;
                while (x >= xlo) {
                    while (j < int(vup.size()) and vup[j] > x) j++;
                    if (j < int(vup.size())) {
                        vup.insert(vup.begin() + j, x);
                        vup.pop_back();
                    } else {
                        break;
                    }
                    x = mat[mode][0][x][i];
                }
                x = mat[mode][1][cx - 1][i];
                j = 0;
                while (x < xhi) {
                    while (j < int(vdown.size()) and vdown[j] < x) j++;
                    if (j < int(vdown.size())) {
                        vdown.insert(vdown.begin() + j, x);
                        vdown.pop_back();
                    } else {
                        break;
                    }
                    x = mat[mode][1][x][i];
                }
                REP(k, K + 1) ret += -(vup[k + 1] - vup[k]) * (vdown[K - k + 1] - vdown[K - k]);
            }
        }
    };

    auto rec = [&](auto &&self, int xlo, int xhi, int ylo, int yhi) -> void {
        const int wx = xhi - xlo, wy = yhi - ylo;
        if (!wx or !wy) return;

        if (wx == 1 and wy == 1) {
            if (S[xlo][ylo] == '0' + K) ret++;
            return;
        }
        if (wx > wy) {
            divconq2d(1, xlo, xhi, ylo, yhi);
            self(self, xlo, (xlo + xhi) / 2, ylo, yhi);
            self(self, (xlo + xhi) / 2, xhi, ylo, yhi);
        } else if (wy > 1) {
            divconq2d(0, ylo, yhi, xlo, xhi);
            self(self, xlo, xhi, ylo, (ylo + yhi) / 2);
            self(self, xlo, xhi, (ylo + yhi) / 2, yhi);
        }
    };
    rec(rec, 0, H, 0, W);
    cout << ret << '\n';
}