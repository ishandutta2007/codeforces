#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int CYCLE;
vector<vector<int>> GT;
void grundy_simulate(vector<int> X) {
    GT.assign(3, vector<int>(1000));
    map<int, int> hash;
    vector<int> vh(1000);
    FOR(x, 1, GT[0].size()) {
        REP(d, 3) {
            vector<int> nd(5);
            REP(e, 3) {
                if (d and d == e) continue;
                int y = max(0, x - X[e]);
                nd[GT[e][y]] = 1;
            }
            int g = 0;
            while (nd[g]) g++;
            GT[d][x] = g;
        }
        vh[x] = GT[0][x] + GT[1][x] * 4 + GT[2][x] * 16;
        if (x >= 5) {
            int h = vh[x] + (vh[x - 1] << 6) + (vh[x - 2] << 12) + (vh[x - 3] << 18) + (vh[x - 4] << 24);
            if (hash.count(h)) {
                CYCLE = x - hash[h];
                REP(d, 3) GT[d].resize(x + 1);
                break;
            }
            hash[h] = x;
        }
    }
}



int grundy(lint A, int status) {
    if (A <= 0) return 0;
    if (A >= GT[0].size()) {
        lint sup = A - GT[0].size() + 1;
        A = A - (sup + CYCLE - 1) / CYCLE * CYCLE;
    }
    return GT[status][A];
}

int solve()
{
    int N;
    vector<int> X(3);
    cin >> N >> X;
    grundy_simulate(X);
    int gall = 0;
    vector<int> grundies;
    while (N--) {
        lint A;
        cin >> A;
        int g0 = grundy(A, 0);
        gall ^= g0;
        REP(d, 3) grundies.push_back(g0 ^ grundy(A - X[d], d));
    }
    int ret = 0;
    for (auto x : grundies) ret += (x == gall);
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << "\n";
}