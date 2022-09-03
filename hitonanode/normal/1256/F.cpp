#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
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

bool solve()
{
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    string Ssort = S, Tsort = T;
    sort(ALL(Ssort));
    sort(ALL(Tsort));
    if (Ssort != Tsort) return false;
    vector<int> cou(26);
    for (auto c : S) cou[c - 'a']++;
    if (*max_element(ALL(cou)) > 1) return true;

    BIT<lint> bitS(26), bitT(26);
    lint revS = 0, revT = 0;
    for (auto c : S)
    {
        revS += bitS.sum(c - 'a');
        bitS.add(c - 'a' + 1, 1);
    }
    for (auto c : T)
    {
        revT += bitT.sum(c - 'a');
        bitT.add(c - 'a' + 1, 1);
    }
    return (revS + revT) % 2 == 0;
}

int main()
{
    int Q;
    cin >> Q;
    while (Q--) cout << (solve() ? "YES" : "NO") << endl;
}