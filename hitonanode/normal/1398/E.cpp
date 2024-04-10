#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template <typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template <typename V, typename T> void ndfill(V &x, const T &val) { x = val; }
template <typename V, typename T> void ndfill(vector<V> &vec, const T &val) { for (auto &v : vec) ndfill(v, val); }
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
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

int main()
{
    int N;
    cin >> N;

    lint tot = 0;

    multiset<int> v0, v1;

    multiset<pint> twice;
    int twice_nb0 = 0, twice_nb1 = 0;
    lint twice_sum = 0;

    auto twice_rm = [&]() {
        auto [val, tp] = *twice.begin();
        twice.erase(twice.begin());
        (tp ? twice_nb1 : twice_nb0)--;
        twice_sum -= val;
        (tp ? v1 : v0).insert(val);
    };

    while (N--)
    {
        int tp, d;
        cin >> tp >> d;

        tot += d;

        if (d < 0)
        {
            pint p(-d, tp);
            if (twice.count(p))
            {
                twice.erase(twice.lower_bound(p));
                (tp ? twice_nb1 : twice_nb0)--;
                twice_sum += d;
            }
            else if (tp == 0) v0.erase(v0.lower_bound(-d));
            else v1.erase(v1.lower_bound(-d));
        }
        else
        {
            (tp ? v1 : v0).insert(d);
        }

        while (twice.size() > twice_nb1 + v1.size()) twice_rm();


        while (twice.size() < twice_nb1 + v1.size())
        {
            if (v0.empty() or (v1.size() and *prev(v0.end()) < *prev(v1.end())))
            {
                lint v = *prev(v1.end());
                twice.emplace(v, 1);
                twice_nb1++;
                twice_sum += v;
                v1.erase(prev(v1.end()));
            }
            else
            {
                lint v = *prev(v0.end());
                twice.emplace(v, 0);
                twice_nb0++;
                twice_sum += v;
                v0.erase(prev(v0.end()));
            }
        }

        while (twice.size())
        {
            auto lo = twice.begin()->first;
            if (v1.size() and *prev(v1.end()) > lo)
            {
                twice.emplace(*prev(v1.end()), 1);
                twice_sum += *prev(v1.end());
                v1.erase(prev(v1.end()));
                twice_nb1++;
            }
            else if (v0.size() and *prev(v0.end()) > lo)
            {
                twice.emplace(*prev(v0.end()), 0);
                twice_sum += *prev(v0.end());
                v0.erase(prev(v0.end()));
                twice_nb0++;
            }
            else break;
            twice_rm();
        }

        lint ret = tot + twice_sum;
        dbg(ret);
        dbg(twice_nb0);
        dbg(twice_nb1);
        dbg(twice);
        dbg(v0);
        dbg(v1);
        if (twice_nb1 and !twice_nb0)
        {
            ret -= twice.begin()->first;
            if (v0.size()) ret += *prev(v0.end());
        }
        cout << ret << '\n';
        dbg("OK");
    }
    // vector<pint> V(N);
    // vector<int> Z;
    // REP(i, N)
    // {
    //     cin >> V[i].first >> V[i].second;
    //     if (V[i].second > 0) Z.emplace_back(V[i].second);
    // }

}