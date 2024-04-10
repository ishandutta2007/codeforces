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
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

// 1-indexed BIT (i : [1, len])
template<typename T>
struct BIT
{
    int len;
    vector<T> val;
    BIT(int num) : len(num), val(num + 1) {}
    BIT() : BIT(0) {}
    void reset() { fill(val.begin(), val.end(), 0); }
    void add(int pos, T v) { while (pos > 0 and pos <= len) val[pos] += v, pos += pos & -pos; }
    T sum(int pos) const // (0, pos]
    {
        T res = 0;
        while (pos > 0) res += val[pos], pos -= pos & -pos;
        return res;
    }
};
template<typename T> ostream &operator<<(ostream &os, const BIT<T> &b){ T prv = 0; os << "["; REP(i, b.len) { T nxt = b.sum(i + 1); os << nxt - prv << ","; prv = nxt; } os << "]"; return os; }


int main()
{
    int N;
    cin >> N;
    vector<lint> S(N);
    cin >> S;
    vector<lint> P(N);
    BIT<lint> bit(N + 1);

    REP(i, N) bit.add(i + 1, i + 1);

    set<int> remain;
    REP(i, N) remain.insert(i + 1);

    IREP(i, N)
    {
        int l = 0, r = N; // (l. r]
        while (r - l > 1)
        {
            int c = (l + r) / 2;
            if (bit.sum(c - 1) >= S[i]) r = c;
            else l = c;
        }
        r = *remain.lower_bound(r);
        remain.erase(r);
        P[i] = r;
        bit.add(r, -r);
    }
    REP(i, N) printf("%lld ", P[i]);
    puts("");
}