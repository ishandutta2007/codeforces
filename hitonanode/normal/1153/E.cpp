#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

bool isswap;

int q(int a, int b, int c, int d)
{
    if (isswap) swap(a, b), swap(c, d);
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout);
    int ret;
    cin >> ret;
    return ret % 2;
}

void ans(vector<int> out)
{
    printf("!");
    for (auto v : out) printf(" %d", v);
    puts("");
}

int main()
{
    isswap = false;
    int N;
    cin >> N;
    vector<int> H(N + 1), W(N + 1), Hcand, Wcand;
    for (int i = 1; i <= N; i++)
    {
        H[i] = q(1, 1, i, N);
        if (H[i] != H[i - 1]) Hcand.push_back(i);
    }
    for (int i = 1; i <= N; i++)
    {
        W[i] = q(1, 1, N, i);
        if (W[i] != W[i - 1]) Wcand.push_back(i);
    }
    
    if (Hcand.size() and Wcand.size())
    {
        vector<int> out;
        for (auto h : Hcand) for (auto w : Wcand)
        {
            if (q(h, w, h, w)) out.push_back(h), out.push_back(w);
        }
        ans(out);
        return 0;
    }

    if (Hcand.empty()) swap(Hcand, Wcand), isswap = true;

    int l = 0, r = N;
    while (r - l > 1)
    {
        int c = (l + r) / 2;
        if (q(1, 1, Hcand[0], c)) r = c;
        else l = c;
    }
    vector<int> out{Hcand[0], r, Hcand[1], r};
    if (isswap) swap(out[0], out[1]), swap(out[2], out[3]);
    ans(out);
}