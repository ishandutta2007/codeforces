#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int solve()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    cin >> S;
    int np = 0, na = 0;
    for (auto v : S) for (auto c : v) (c == 'A' ? na : np)++;
    if (na == 0) return -1;
    if (np == 0) return 0;
    int ret = 4;

    REP(_, 2) {
        if (H == 0) {
            if (S[0][0] == 'A' or S[0].back() == 'A') mmin(ret, 1);
            mmin(ret, 2);
        }
        if (S[0] == string(W, 'A')) mmin(ret, 1);
        if (S.back() == string(W, 'A')) mmin(ret, 1);

        if (S[0][0] == 'A') mmin(ret, 2);
        if (S[0].back() == 'A') mmin(ret, 2);
        if (S.back().back() == 'A') mmin(ret, 2);

        for (auto v : S) if (v == string(W, 'A')) mmin(ret, 2);

        for (auto c : S[0]) if (c == 'A') mmin(ret, 3);
        for (auto c : S.back()) if (c == 'A') mmin(ret, 3);

        vector<string> ST(W);
        REP(i, H) REP(j, W) ST[j] += S[i][j];
        S = ST;
        swap(H, W);
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int ret = solve();
        if (ret < 0) puts("MORTAL");
        else printf("%d\n", ret);
    }
}