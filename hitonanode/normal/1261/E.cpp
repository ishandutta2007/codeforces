#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;



int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    vector<string> ret(N + 1);
    REP(i, N + 1) REP(_, N) ret[i] += '0';

    vector<pint> AS(N);
    REP(i, N) AS[i] = make_pair(A[i], i);

    sort(AS.rbegin(), AS.rend());

    REP(j, N)
    {
        int i = AS[j].second;

        int h = j;
        REP(_, A[i])
        {
            ret[h][i]++;
            h++;
            if (h >= (int)ret.size()) h = 0;
        }
    }
    vector<int> use(N + 1, 1);
    REP(i, N + 1)
    {
        int cou1 = 0;
        for (auto c : ret[i]) if (c == '1') cou1++;
        if (!cou1) use[i] = 0;
    }
    printf("%d\n", (int)accumulate(ALL(use), 0));
    REP(i, N + 1) if (use[i])
    {
        printf("%s\n", ret[i].c_str());
    }
}