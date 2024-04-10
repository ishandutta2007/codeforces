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
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
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

pair<vector<int>, vector<int>> divide(vector<int> V) {
    sort(ALL(V));
    int tot = accumulate(ALL(V), 0);
    vector<int> ret[2];
    if (tot % 2) return {ret[0], ret[1]};
    vector<int> dp(tot / 2 + 1);
    dp[0] = 1;
    for (auto x : V) {
        IFOR(i, x, dp.size()) {
            if (dp[i] == 0 and dp[i - x]) {
                dp[i] = x;
            }
        }
    }

    if (dp.back()) {
        multiset<int> ok;
        for (auto x : V) ok.insert(x);

        int now = tot / 2;
        while (now) {
            ret[0].emplace_back(dp[now]);
            ok.erase(ok.lower_bound(dp[now]));
            now -= dp[now];
        }
        for (auto x : ok) {
            ret[1].emplace_back(x);
        }
    }
    return { ret[0], ret[1] };
}

void solve()
{
    int H;
    cin >> H;
    vector<int> L(H);
    cin >> L;
    int V;
    cin >> V;
    vector<int> P(V);
    cin >> P;
    if (H != V) {
        cout << "No\n";
        return;
    }
    auto [h1, h2] = divide(L);
    auto [w1, w2] = divide(P);

    if (h1.empty() or w1.empty()) {
        cout << "No\n";
        return;
    }
    if (h1.size() > h2.size()) swap(h1, h2);
    sort(h1.rbegin(), h1.rend());
    sort(h2.rbegin(), h2.rend());
    for (auto &x : h2) x *= -1;
    h1.insert(h1.end(), ALL(h2));

    if (w1.size() < w2.size()) swap(w1, w2);
    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());

    for (auto &x : w2) x *= -1;
    w1.insert(w1.end(), ALL(w2));
    int x = 0, y = 0;

    cout << "Yes\n";
    REP(i, H + V) {
        cout << x << ' ' << y << '\n';
        if (i % 2 == 0) x += h1[i / 2];
        else y += w1[i / 2];
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}