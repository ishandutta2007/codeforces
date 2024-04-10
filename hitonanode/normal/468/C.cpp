#include <bits/stdc++.h>
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
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

void solve1(lint A) {
    string ret;
    while (A) {
        lint d = min(A, 9LL);
        ret += to_string(d);
        A -= d;
    }
    cout << ret << ' ' << ret << '\n';
    exit(0);
}

__int128 str2i128(std::string str) {
    __int128 ret = 0;
    bool minus = false;
    for (auto c : str) {
        if (c == '-')
            minus = true;
        else
            ret = ret * 10 + c - '0';
    }
    return minus ? -ret : ret;
}
std::istream &operator>>(std::istream &is, __int128 &x) {
    std::string s;
    return is >> s, x = str2i128(s), is;
}
std::ostream &operator<<(std::ostream &os, const __int128 &x) {
    __int128 tmp = x;
    if (tmp == 0) return os << 0;
    std::vector<int> ds;
    if (tmp < 0) {
        os << '-';
        while (tmp) {
            int d = tmp % 10;
            if (d > 0) d -= 10;
            ds.emplace_back(-d), tmp = (tmp - d) / 10;
        }
    } else {
        while (tmp) ds.emplace_back(tmp % 10), tmp /= 10;
    }
    std::reverse(ds.begin(), ds.end());
    for (auto i : ds) os << i;
    return os;
}

vector<__int128> DC;
vector<__int128> p10;

__int128 cnt(lint x) {
    __int128 ret = 0;
    IREP(d, p10.size()) {
        lint e = x / p10[d];
        if (e) {
            ret += DC[d] * e + p10[d] * e * (e - 1) / 2;
            x -= e * p10[d];
            ret += (x + 1) * e;
        }
    }
    return ret;
}


int single(lint A) {
    int ret = 0;
    while (A) {
        ret += A % 10;
        A /= 10;
    }
    return ret;
}

int main()
{
    lint A;
    cin >> A;
    if (A <= 1800) solve1(A);

    DC.resize(18);
    p10.resize(18, 1);
    FOR(i, 1, p10.size()) p10[i] = p10[i - 1] * 10;

    FOR(i, 1, DC.size()) {
        DC[i] = 45 * i;
        REP(_, i - 1) DC[i] *= 10;
    }
    // dbg(DC);
    // dbg(p10);
    // FOR(d, 1, 100) dbg(plint(d, (cnt(d))));

    lint lo = 0, hi = 100000000000000000LL;
    while (hi - lo > 1) {
        lint c = (hi + lo) / 2;
        (cnt(c) >= A ? hi : lo) = c;
    }
    lint l = 1, r = hi;
    __int128 nb = cnt(hi);
    while (nb != A) {
        if (nb > A) {
            nb -= single(l);
            l++;
        } else {
            r++;
            nb += single(r);
        }
    }
    cout << l << ' ' << r << '\n';
}