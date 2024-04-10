#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
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
#include <type_traits>
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
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }
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
#define dbgif(cond, x) ((cond) ? cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl : cerr)
#else
#define dbg(x) 0
#define dbgif(cond, x) 0
#endif

// Aho-Corasick algorithm
// Verify: <http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5101653>
//         <https://yukicoder.me/submissions/598606>
// Complexity:
// - add(): O(|keyword_i|)
// - build_aho_corasick(): O(\sum_i |keyword_i|)
// - match() : O(\sum_i |keyword_i| + |str|)
template <class T, int (*char2int)(char)> struct AhoCorasick {
    bool built;
    const int D;
    std::vector<T> node;
    AhoCorasick(int D_) : built(false), D(D_), node(1, D) {}
    AhoCorasick operator=(const AhoCorasick &rhs) { return AhoCorasick(rhs.D); }

    void enter_child(int n, int nn, int c) { node[n].setch(c, nn); }

    std::vector<int> endpos;
    int add(const std::string &keyword) { // Enter_in_tree() in [1]
        built = false;
        int n = 0;
        for (const auto &cc : keyword) {
            int c = char2int(cc), nn = node[n].Goto(c);
            if (!nn) {
                nn = node.size();
                enter_child(n, nn, c), node.emplace_back(D);
            }
            n = nn;
        }
        return endpos.push_back(n), n;
    }

    void complete_failure(int n, int nn, int c) {
        int m = node[n].fail, mm = node[m].Goto(c);
        while (m and !mm) m = node[m].fail, mm = node[m].Goto(c);
        node[nn].fail = mm;
    }

    std::vector<int> visorder; // BFS order of node ids
    void build() {             // Build_failure() in [1]
        visorder.clear();
        for (auto p : node[0]) {
            if (p.second) visorder.push_back(p.second);
        }
        for (size_t p = 0; p < visorder.size(); p++) {
            int n = visorder[p];
            for (auto p : node[n]) {
                int c = p.first, nn = p.second;
                if (nn) visorder.push_back(nn), complete_failure(n, nn, c);
            }
        }
        built = true;
    }

    int step(int now, int d) {
        while (now and !node[now].Goto(d)) now = node[now].fail;
        return node[now].Goto(d);
    }
};

struct TrieNodeV {
    std::array<int, 26> ch;
    int fail;
    TrieNodeV(int D = 0) : fail(0) { ch.fill(0); }
    int Goto(int d) { return ch[d]; }
    void setch(int d, int i) { ch[d] = i; }

    struct iterator {
        int i;
        std::array<int, 26>::iterator iter;
        iterator operator++() { return {++i, ++iter}; }
        std::pair<int, int> operator*() { return std::make_pair(i, *iter); }
        bool operator!=(const iterator &rhs) { return iter != rhs.iter; }
    };
    iterator begin() { return {0, ch.begin()}; }
    iterator end() { return {int(ch.size()), ch.end()}; }
};

int c2ia(char c) { return c - 'a'; }

// MP (Morris-Pratt) algorithm (length of longest nontrivial matching for
// prefix & suffix of s[0:i] for each i)
// Input: std::string of length N
// Output: std::vector<int> of size N + 1
// Complexity: O(N)
// Sample:
// - `teletelepathy` -> [-1, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 1, 0, 0]
// Reference: <https://snuke.hatenablog.com/entry/2014/12/01/235807>
std::vector<int> mp_algorithm(std::string s) {
    int N = s.length();
    std::vector<int> ret(N + 1, -1);
    int j = -1;
    for (int i = 0; i < N; i++) {
        while (j >= 0 and s[i] != s[j]) j = ret[j];
        ret[i + 1] = ++j;
    }
    return ret;
}


int main() {
    string S;
    cin >> S;
    AhoCorasick<TrieNodeV, c2ia> trie(26);
    trie.add(S);
    trie.build();

    const int N = S.size();

    int Q;
    cin >> Q;

    vector<int> shifts;
    FOR(s, 1, 11) {
        if (s > S.size()) continue;
        if (S.substr(s) == S.substr(0, S.size() - s)) shifts.push_back(s);
    }

    vector steps(26, vector<int>(N + 1, -1));

    while (Q--) {
        string t;
        cin >> t;
        if (S.size() < t.size()) {
            auto mp = mp_algorithm(S + t);
            FOR(i, mp.size() - t.size(), mp.size()) cout << mp[i] << ' ';
        } else {
            int now = N;
            REP(d, t.size()) {
                char c = t.at(d);
                // S += c;
                int c2iac = c2ia(c);
                if (steps[c2iac][now] < 0) steps[c2iac][now] = trie.step(now, c2iac);
                now = steps[c2iac][now];
                int tmp = now;

                for (int g : shifts) {
                    bool match = true;
                    REP(j, d + 1) if (t[j] != (j - g >= 0 ? t[j - g] : S[N + j - g])) {
                        match = false;
                        break;
                    }
                    if (match) {
                        chmax(tmp, N + d + 1 - g);
                        break;
                    }
                }

                cout << tmp << ' ';
            }

            // REP(_, t.size()) S.pop_back();
        }
        cout << '\n';
    }
}