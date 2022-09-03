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
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

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
    vector<int> A(N), B(N);
    vector<int> Binv(N + 1);
    cin >> A >> B;
    reverse(ALL(A));
    reverse(ALL(B));
    REP(i, N) Binv[B[i]] = i + 1;

    int ret = 0;
    BIT<int> bit(N);
    for (auto x : A)
    {
        bit.add(Binv[x], 1);
        if (bit.sum(Binv[x]) < Binv[x])
        {
            ret++;
        }
    }
    cout << ret << endl;
}