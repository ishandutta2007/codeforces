#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(7); }; } fast_ios_;
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

template <typename T>
vector<T> AC(vector<T> V) {
    int N = V.size();
    vector<T> ret(N + 1);
    REP(i, N) ret[i + 1] = ret[i] + V[i];
    return ret;
}

// Solve ax^2 + bx + c = 0.
// retval: (# of solutions (-1 == inf.), solutions(ascending order))
// Verify: <https://yukicoder.me/problems/no/955> <https://atcoder.jp/contests/tricky/tasks/tricky_2>
template <typename Float>
std::pair<int, std::vector<Float>> quadratic_solver(Float A, Float B, Float C)
{
    if (B < 0)
        A = -A, B = -B, C = -C;
    if (A == 0) {
        if (B == 0) {
            if (C == 0) return std::make_pair(-1, std::vector<Float>{});  // all real numbers
            else return std::make_pair(0, std::vector<Float>{});  // no solution
        }
        else return std::make_pair(1, std::vector<Float>{-C / B});
    }
    Float D = B * B - 4 * A * C;
    // if (D < 0) return std::make_pair(0, std::vector<Float>{});
    if (D <= 0) return std::make_pair(1, std::vector<Float>{-B / (2 * A)});
    Float ret1 = (-B - sqrt(D)) / (2 * A), ret2 = C / A / ret1;
    if (ret1 > ret2) swap(ret1, ret2);
    return std::make_pair(2, std::vector<Float>{ret1, ret2});
}

int main()
{
    int N;
    cin >> N;
    vector<double> pmax(N), pmin(N);
    cin >> pmax >> pmin;

    const vector<double> PH = AC(pmax), PL = AC(pmin);
    vector<double> Pa{0}, Pb{0};
    REP(i, N) {
        auto [nb, vec] = quadratic_solver<double>(1.0, -(PH[i + 1] + PL[i + 1]), PH[i + 1]);
        // if (vec.empty()) vec = {Pa.back(), Pb.back()};
        Pa.emplace_back(vec[0]);
        Pb.emplace_back(vec.back());
    }
    Pa.back() = 1;
    Pb.back() = 1;
    REP(i, N) cout << Pa[i + 1] - Pa[i] << ' ';
    cout << '\n';
    REP(i, N) cout << Pb[i + 1] - Pb[i] << ' ';
    cout << '\n';
}