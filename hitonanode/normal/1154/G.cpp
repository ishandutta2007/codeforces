#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////

vector<int> contained_prime(int N) // primes in [2, N]
{
    vector<int> ans(N + 1);
    iota(ans.begin(), ans.end(), 0);
    FOR(i, 2, N + 1) if (ans[i] == i)
    {
        for (int j = i; j <= N; j += i)
        {
            ans[j] = i;
        }
    }
    return ans;
}

vector<int> primeinfo;
vector<int> divisors(int n)
{
    map<int, int> factor;
    while (n > 1)
    {
        factor[primeinfo[n]]++;
        n /= primeinfo[n];
    }
    vector<int> now{1};
    for (auto pa : factor)
    {
        REP(i, now.size())
        {
            int d = 1;
            REP(_, pa.second)
            {
                d *= pa.first;
                now.push_back(now[i] * d);
            }
        }
    }
    return now;
}

int main()
{
    primeinfo = contained_prime(10000000);
    int N;
    cin >> N;
    vector<int> A(N), B;
    int a, b;
    cin >> A;
    B = A;
    sort(ALL(A));

    lint ret = 1LL * A[0] * A[1] / __gcd(A[0], A[1]);
    a = A[0], b = A[1];
    map<int, int> ac;
    for (auto v : A) ac[v]++;
    for (auto pa : ac) if (pa.second > 1) if (mmin(ret, (lint)pa.first)) a = b = pa.first;

    auto itr = unique(ALL(A));
    A.erase(itr, A.end());

    vector<vector<int>> g2a(10000001);
    for (auto a : A)
    {
        for (auto g : divisors(a)) if (g > 1) g2a[g].emplace_back(a);
    }
    FOR(g, 2, 10000001) if (g2a[g].size() > 1)
    {
        int x = *min_element(ALL(g2a[g]));
        int y = 1e9;
        for (auto yy : g2a[g]) if (x != yy) mmin(y, yy);
        if (mmin(ret, 1LL * x * y / g)) a = x, b = y;
    }

    int i = 0, j = 0;
    while (B[i] != a) i++;
    if (a == b) j = i + 1;
    while (B[j] != b) j++;
    if (i > j) swap(i, j);
    cout << i + 1 << " " << j + 1 << endl;
}