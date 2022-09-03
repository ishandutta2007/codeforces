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
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////

int main()
{
    int H, W;
    cin >> H >> W;
    if (H == 1 and W == 1)
    {
        puts("0");
    }
    else if (H == 1)
    {
        REP(i, W) printf("%d ", i + 2);
    }
    else if (W == 1) {
        REP(i, H) printf("%d\n", i + 2);
    }
    else
    {
        vector<lint> X, Y;
        if (H == 2 or W == 2)
        {
            X = {2, 3};
            Y = {1};
            REP(i, max(H, W) - 1) Y.emplace_back(i + 4);

            if (W == 2) swap(X, Y);
        }
        else
        {
            X = {2, 3};
            Y = {1, 4, 5};
            REP(i, H + W - 5) if ((int)X.size() < H) X.emplace_back(i + 6);
            else Y.emplace_back(i + 6);
        }

        vector<vector<lint>> ret(H, vector<lint>(W));
        REP(i, H) REP(j, W) ret[i][j] = X[i] * Y[j] / __gcd(X[i], Y[j]);
        REP(i, H)
        {
            REP(j, W) printf("%lld ", ret[i][j]);
            puts("");
        }
    }
}