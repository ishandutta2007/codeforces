#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int solve()
{
    int N, K, Z;
    cin >> N >> K >> Z;
    vector<int> A(N);
    cin >> A;
    vector<int> score(Z + 2, -2e9);
    score[0] = A[0];
    REP(i, K)
    {
        IREP(z, Z + 1)
        {
            int now = i - z * 2;
            if (now >= 0)
            {
                if (now) chmax(score[z + 1], score[z] + A[now - 1]);
                chmax(score[z], score[z] + A[now + 1]);
            }
        }
    }
    return *max_element(score.begin(), score.begin() + Z + 1);
}
int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}