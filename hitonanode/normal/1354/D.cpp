#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

// 1-indexed BIT (i : [1, len])
template <typename T>
struct BIT : std::vector<T>
{
    BIT(int len = 0) : std::vector<T>(len + 1) {}
    void reset() { fill(this->begin(), this->end(), 0); }
    void add(int pos, T v) {
        while (pos > 0 and pos < (int)this->size()) (*this)[pos] += v, pos += pos & -pos;
    }
    T sum(int pos) const { // (0, pos]
        T res = 0;
        while (pos > 0) res += (*this)[pos], pos -= pos & -pos;
        return res;
    }
    friend std::ostream &operator<<(std::ostream &os, const BIT &bit) {
        T prv = 0;
        os << '[';
        for (int i = 1; i < (int)bit.size(); i++) {
            T now = bit.sum(i);
            os << now - prv << ",";
            prv = now;
        }
        os << ']';
        return os;
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> AK(N), K(Q);
    cin >> AK >> K;
    for (auto x : K) if (x > 0) AK.emplace_back(x);

    sort(ALL(AK));
    vector<int> kpos(Q, -1);

    REP(i, Q) if (K[i] > 0)
    {
        int j = prev(upper_bound(ALL(AK), K[i])) - AK.begin();
        kpos[i] = j;
        AK[j]++;
    }
    REP(i, Q) if (kpos[i] >= 0) AK[kpos[i]] = 1e9;
    BIT<int> bit(AK.size());
    REP(i, AK.size()) if (AK[i] != 1e9) bit.add(i + 1, 1);

    REP(i, Q) if (kpos[i] >= 0) AK[kpos[i]] = K[i];

    REP(i, Q)
    {
        if (K[i] > 0)
        {
            bit.add(kpos[i] + 1, 1);
        }
        else
        {
            int lo = 0, hi = AK.size();
            while (hi - lo > 1)
            {
                int c = (lo + hi) / 2;
                if (bit.sum(c) >= -K[i]) hi = c;
                else lo = c;
            }
            bit.add(hi, -1);
        }
    }

    if (bit.sum(AK.size()) == 0) puts("0");
    else
    {
        int i = 1;
        while (!bit.sum(i)) i++;
        cout << AK[i - 1] << '\n';
    }
}