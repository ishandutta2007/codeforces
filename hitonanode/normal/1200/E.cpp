#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<int> mp_algorithm(string s) {
    vector<int> ret(s.length() + 1);
    ret[0] = -1;
    int j = -1;
    REP(i, s.length())
    {
        while (j >= 0 and s[i] != s[j]) j = ret[j];
        j++;
        ret[i + 1] = j;
    }
    return ret;
}

int main()
{
    int NNN;
    cin >> NNN;
    string ret;
    REP(_, NNN)
    {
        string s;
        cin >> s;
        int N = s.length();
        int M = min(N, (int)ret.length());
        string smp = s + "-" + ret.substr(ret.length() - M);
        vector<int> vec = mp_algorithm(smp);
        int kyo = vec.back();
        // FOR(i, N + 1, vec.size()) if (i + vec[i] == (int)vec.size()) mmax(kyo, vec[i]);
        // dbg(vec);
        // dbg(smp);
        // dbg(kyo);
        ret += s.substr(kyo);
    }
    cout << ret << endl;
}