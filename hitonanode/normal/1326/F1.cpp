#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int N;
vector<string> str_;

int next_combination(int comb)
{
    int x = comb & -comb, y = comb + x;
    return ((comb & ~y) / x >> 1) | y;
}

int str[15][15];

int main()
{
    cin >> N;
    str_.resize(N);
    cin >> str_;
    REP(i, N) REP(j, N) str[i][j] = (str_[i][j] == '1');
    vector<lint> ret(1 << (N - 1));
    if (N == 2) {
        if (str[0][1] == 0) {
            ret = {2, 0};
        }
        else {
            ret = {0, 2};
        }
    }
    else {
        REP(c, N) {
            const int S = (1 << N) - 1 - (1 << c);
            const int nt = N / 2, nu = N - 1 - nt;

            int T = (1 << nt) - 1;
            if (T & (1 << c)) {
                T += 1 << nt;
                T -= 1 << c;
            }

            while (T < (1 << N)) {
                int U = S - T;
                vector<int> vt, vu;
                REP(d, N) if ((T >> d) & 1) vt.push_back(d);
                REP(d, N) if ((U >> d) & 1) vu.push_back(d);
                vector<int> dpt(1 << nt), dpu(1 << nu);
                do {
                    int st = 0;
                    REP(i, nt - 1) {
                        st *= 2;
                        if (str[vt[i]][vt[i + 1]]) st++;
                    }
                    st *= 2;
                    if (str[vt.back()][c]) st++;
                    dpt[st]++;
                } while (next_permutation(ALL(vt)));

                do {
                    int st = 0;
                    if (str[vu[0]][c]) st++;
                    REP(i, nu - 1) {
                        st *= 2;
                        if (str[vu[i]][vu[i + 1]]) st++;
                    }
                    dpu[st]++;
                } while (next_permutation(ALL(vu)));

                REP(s1, dpt.size()) REP(s2, dpu.size()) ret[(s1 << nu) + s2] += 1LL * dpt[s1] * dpu[s2];
                T = (T & ((1 << c) - 1)) + ((T >> (c + 1)) << c);
                T = next_combination(T);
                T = (T & ((1 << c) - 1)) + ((T >> c) << (c + 1));
            }
        }
    }
    for (auto x : ret) printf("%lld ", x);
    puts("");
}