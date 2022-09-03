#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
string solve()
{
    string S;
    cin >> S;
    int N = S.length();
    vector<vector<int>> a(3, vector<int>(N + 1));
    REP(i, N) {
        if (S[i] - 'a' >= 0 and S[i] - 'a' < 26) a[0][i + 1]++;
        if (S[i] - 'A' >= 0 and S[i] - 'A' < 26) a[1][i + 1]++;
        if (S[i] - '0' >= 0 and S[i] - '0' < 10) a[2][i + 1]++;
        REP(d, 3) a[d][i + 1] += a[d][i];
    }

    int ntype = 0;
    REP(d, 3) if (a[d].back()) ntype++;
    if (ntype == 3) return S;

    if (ntype == 2) REP(i, N) {
        vector<int> v(3);
        REP(d, 3) if (a[d][i] or a[d].back() - a[d][i + 1]) v[d] = 1;
        if (accumulate(ALL(v), 0) == 2) {
            int j = 0;
            while (v[j]) j++;
            S[i] = (j == 0 ? 'a' : (j == 1 ? 'A' : '0'));
            return S;
        }
    }
    if (a[0][1]) S[1] = 'A', S[2] = '0';
    if (a[1][1]) S[1] = 'a', S[2] = '0';
    if (a[2][1]) S[1] = 'A', S[2] = 'a';
    return S;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}