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
    vector<lint> H(N);
    cin >> H;
    stack<plint> st;
    st.emplace(H[0], 1);
    FOR(i, 1, N)
    {
        lint hnew = H[i];
        while (true)
        {
            if (st.size() == 1)
            {
                auto [h, len] = st.top();
                st.pop();
                lint d = (hnew - (h + len - 1)) / (len + 1);
                h += d;
                hnew -= d * len;

                lint k = max(0LL, hnew - (h + len));
                if (k)
                {
                    st.emplace(h + 1, k);
                    st.emplace(h + k, len - k + 1);
                }
                else if (h + len == hnew)
                {
                    st.emplace(h, len + 1);
                }
                else if (h + len - 1 == hnew)
                {
                    st.emplace(h, len);
                    st.emplace(hnew, 1);
                }
                else
                {
                    assert(8);
                }
                break;
            }
            else
            {
                auto [h, len] = st.top();
                if (h + len == hnew)
                {
                    st.top().second++;
                    break;
                }
                else if (h + len - 1 == hnew)
                {
                    st.emplace(hnew, 1);
                    break;
                }
                else
                {
                    st.pop();
                    lint d = max(0LL, hnew - (h + len));
                    if (d >= len)
                    {
                        st.top().second += len;
                        hnew -= len;
                        continue;
                    }
                    else
                    {
                        st.top().second += d;
                        int v = st.top().first + st.top().second - 1;
                        st.emplace(v, len - d);
                        hnew -= d;
                    }
                }
            }
        }
    }
    vector<lint> ret;
    while (st.size())
    {
        auto [h, l] = st.top();
        st.pop();
        for (lint x = h + l - 1; x >= h; x--) ret.emplace_back(x);
    }
    reverse(ret.begin(), ret.end());
    for (auto x : ret) cout << x << ' ';
    cout << '\n';
}