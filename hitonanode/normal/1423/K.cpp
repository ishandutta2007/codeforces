#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
    fast_ios() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); };
} fast_ios_;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
//
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args>
void ndarray(vector<T>& vec, const V& val, int len, Args... args)
{
    vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); });
}
template <typename T>
bool chmax(T& m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T>
bool chmin(T& m, const T q) { return m > q ? (m = q, true) : false; }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T>
vector<T> srtunq(vector<T> vec) { return sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()), vec; }
template <typename T>
istream& operator>>(istream& is, vector<T>& vec)
{
    return for_each(begin(vec), end(vec), [&](T& v) { is >> v; }), is;
}

// output
template <typename T, typename V>
ostream& dmpseq(ostream&, const T&, const string&, const string&, const string&);
#if __cplusplus >= 201703L
template <typename... T>
ostream& operator<<(ostream& os, const tuple<T...>& tpl)
{
    return apply([&os](auto&&... args) { ((os << args << ','), ...); }, tpl), os;
}
#endif
//
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '(' << p.first << ',' << p.second << ')'; }
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& x) { return dmpseq<vector<T>, T>(os, x, "[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& x) { return dmpseq<deque<T>, T>(os, x, "deq[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const set<T>& x) { return dmpseq<set<T>, T>(os, x, "{", ",", "}"); }
template <typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_set<T, TH>& x) { return dmpseq<unordered_set<T, TH>, T>(os, x, "{", ",", "}"); }
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& x) { return dmpseq<multiset<T>, T>(os, x, "{", ",", "}"); }
template <typename TK, typename T>
ostream& operator<<(ostream& os, const map<TK, T>& x) { return dmpseq<map<TK, T>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename TK, typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_map<TK, T, TH>& x) { return dmpseq<unordered_map<TK, T, TH>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename T, typename V>
ostream& dmpseq(ostream& os, const T& seq, const string& pre, const string& sp, const string& suf)
{
    return os << pre, for_each(begin(seq), end(seq), [&](V x) { os << x << sp; }), os << suf;
}
template <typename T>
void print(const vector<T>& x) { dmpseq<vector<T>, T>(cout, x, "", " ", "\n"); }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

// Sieve of Eratosthenes
// (*this)[i] = (divisor of i, greater than 1)
// Example: [0, 1, 2, 3, 2, 5, 3, 7, 2, 3, 2, 11, ...]
// Complexity: Space O(MAXN), Time (construction) O(MAXNloglogMAXN)
struct SieveOfEratosthenes : std::vector<int>
{
    std::vector<int> primes;
    SieveOfEratosthenes(int MAXN) : std::vector<int>(MAXN + 1) {
        std::iota(begin(), end(), 0);
        for (int i = 2; i <= MAXN; i++) {
            if ((*this)[i] == i) {
                primes.push_back(i);
                for (int j = i; j <= MAXN; j += i) (*this)[j] = i;
            }
        }
    }
    using T = long long int;
    // Prime factorization for x <= MAXN^2
    // Complexity: O(log x)          (x <= MAXN)
    //             O(MAXN / logMAXN) (MAXN < x <= MAXN^2)
    std::map<T, int> Factorize(T x) {
        assert(x <= 1LL * (int(size()) - 1) * (int(size()) - 1));
        std::map<T, int> ret;
        if (x < int(size())) {
            while (x > 1) {
                ret[(*this)[x]]++;
                x /= (*this)[x];
            }
        }
        else {
            for (auto p : primes) {
                while (!(x % p)) x /= p, ret[p]++;
                if (x == 1) break;
            }
            if (x > 1) ret[x]++;
        }
        return ret;
    }
    std::vector<T> Divisors(T x) {
        std::vector<T> ret{1};
        for (auto p : Factorize(x)) {
            int n = ret.size();
            for (int i = 0; i < n; i++) {
                for (T a = 1, d = 1; d <= p.second; d++) {
                    a *= p.first;
                    ret.push_back(ret[i] * a);
                }
            }
        }
        return ret; // Not sorted
    }
    // Moebius function Table
    // return: [0=>0, 1=>1, 2=>-1, 3=>-1, 4=>0, 5=>-1, 6=>1, 7=>-1, 8=>0, ...]
    std::vector<int> GenerateMoebiusFunctionTable() {
        std::vector<int> ret(size());
        for (int i = 1; i < int(size()); i++) {
            if (i == 1) ret[i] = 1;
            else if ((i / (*this)[i]) % (*this)[i] == 0) ret[i] = 0;
            else ret[i] = -ret[i / (*this)[i]];
        }
        return ret;
    }
};
SieveOfEratosthenes sieve(1000000);

vector<int> solution(1000001, 1);

int main()
{
    int T;
    cin >> T;
    queue<lint> que;
    for (lint d = 2; d <= 1000000; d++) {
        if (sieve[d] == d) que.emplace(d);
        if (que.front() * que.front() == d) que.pop();
        solution[d] = que.size() + 1;
    }
    while (T--) {
        int x;
        cin >> x;
        cout << solution[x] << '\n';
    }
}