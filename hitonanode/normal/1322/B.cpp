#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

lint stupid(vector<int> A)
{
    int ret = 0;
    int N = A.size();
    REP(i, N) REP(j, i) ret ^= (A[i] + A[j]);
    return ret;
}

int main()
{
    int N;
    cin >> N;
    int retxor = 0;
    vector<int> A(N);
    cin >> A;
    N = A.size();
    int ret = 0;
    // dbg(A);
    REP(d, 26)
    {
        vector<int> zero, one;
        int mask = (1 << d) - 1;
        int thres = 1 << d;
        REP(i, N) {
            int a = A[i];
            if ((a >> d) & 1) one.emplace_back(a & mask);
            else zero.emplace_back(a & mask);
        }
        sort(ALL(one));
        sort(ALL(zero));
        lint nb = 0;
        REP(i, zero.size()) {
            int tgt = thres - zero[i];
            auto itr = lower_bound(zero.begin() + i + 1, zero.end(), tgt);
            int j = itr - zero.begin();
            nb += zero.size() - j;

            itr = lower_bound(ALL(one), tgt);
            nb += itr - one.begin();
        }
        REP(i, one.size()) {
            int tgt = thres - one[i];
            auto itr = lower_bound(one.begin() + i + 1, one.end(), tgt);
            int j = itr - one.begin();
            nb += one.size() - j;
        }
        if (nb % 2) ret += 1 << d;
    }
    cout << (ret ^ retxor) << endl;
    // dbg(stupid(A));
}