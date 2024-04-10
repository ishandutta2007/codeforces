#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

constexpr int KMAX = 3001;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<vector<lint>> A(N);
    vector<int> sz(N);
    vector<lint> tot(N);
    REP(i, N) {
        int t;
        cin >> t;
        A[i].resize(t);
        cin >> A[i];
        if (int(A[i].size()) > K) {
            A[i].resize(K);
        }
        sz[i] = A[i].size();
        REP(j, A[i].size() - 1) A[i][j + 1] += A[i][j];
        tot[i] = A[i].back();
    }

    constexpr lint INF = 2e18;
    using arr = array<lint, KMAX>;

    auto ad = [&](int i, arr &a) -> void {
        IREP(k, K + 1 - sz[i])
        {
            chmax(a[k + sz[i]], a[k] + tot[i]);
        }
    };

    lint ret = 0;
    auto solve = [&](auto&& self, int l, int r, arr& ar) -> void {
        if (l + 1 == r) {
            chmax(ret, ar[K]);
            REP(i, sz[l])
            {
                chmax(ret, A[l][i] + ar[K - i - 1]);
            }
            return;
        }
        const int c = (l + r) / 2;
        arr ar2(ar);
        FOR(i, l, c)
        {
            ad(i, ar);
        }
        self(self, c, r, ar);
        FOR(i, c, r)
        {
            ad(i, ar2);
        }
        self(self, l, c, ar2);
    };

    arr ar;
    fill(ar.begin(), ar.end(), -INF);
    ar[0] = 0;
    solve(solve, 0, N, ar);
    cout << ret << '\n';
}