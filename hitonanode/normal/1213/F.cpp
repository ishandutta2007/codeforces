#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> p(N);
    vector<int> q(N);
    cin >> p >> q;

    vector<int> imos(N + 2);

    vector<int> r(N + 1);
    REP(i, N) r[p[i]] = i;
    REP(i, N - 1)
    {
        int a = r[q[i]];
        int b = r[q[i + 1]];
        if (a > b)
        {
            imos[b]++;
            imos[a]--;
        }
    }

    REP(i, N + 1) imos[i + 1] += imos[i];
    int ok = 0;
    REP(i, N)
    {
        if (imos[i] == 0) ok++;
    }
    if (ok < K)
    {
        puts("NO");
    }
    else
    {
        int last_ok = N - 1;
        vector<int> to(N);
        IREP(i, N)
        {
            if (imos[i] == 0) last_ok = i;
            to[i] = last_ok;
        }
        vector<int> ret(N);

        REP(i, N) ret[i] = to[r[i + 1]];
        set<int> s;
        for (auto v : ret) s.insert(v);
        map<int, int> z;
        int k = 0;
        for (auto v : s) z[v] = k++;
        REP(i, N) ret[i] = min(z[ret[i]], K - 1);
        string retstr;
        REP(i, N) retstr += (char)('a' + ret[i]);
        cout << "YES\n" << retstr << endl;
    }
}