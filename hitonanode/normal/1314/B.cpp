#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<int> V;

struct T
{
    int v1, v2, v3;
    T() : v1(-1e9), v2(-1e9), v3(-1e9) {}
};

T merge(T l, T r) {
    T ret;
    REP(_, 2) {
        chmax(ret.v3, l.v3 + max({r.v1, r.v2, r.v3, 0}) + 3);
        chmax(ret.v3, max(l.v1, l.v3) + max(r.v2, r.v3) + 3);
        chmax(ret.v1, l.v1 + max(r.v1, 0) + 1);
        chmax(ret.v2, l.v1 + max(r.v2, 0) + 2);
        chmax(ret.v2, l.v3 + max(r.v2, 0) + 3);
        chmax(ret.v2, l.v2 + max(r.v2, 0) + 2);
        swap(l, r);
    }
    return ret;
};

T dfs(int l, int r) {
    if (r - l == 4) {
        T ret;
        int n = accumulate(V.begin() + l, V.begin() + r, 0);
        if (n >= 3) {
            ret.v3 = 5;
            return ret;
        }
        if (!n) return ret;
        if (n == 1) {
            ret.v1 = 2;
            ret.v2 = 3;
            return ret;
        }
        if ((V[l] and V[l + 1]) or (V[l + 2] and V[l + 3])) {
            ret.v3 = 4;
            return ret;
        }
        else {
            ret.v3 = 5;
            return ret;
        }
    }
    return merge(dfs(l, (l + r) / 2), dfs((l + r) / 2, r));
}
int main()
{
    int N, K;
    cin >> N >> K;
    if (!K) {
        puts("0");
        return 0;
    }
    V.resize(1 << N);
    while (K--)
    {
        int a;
        cin >> a;
        V[a - 1] = 1;
    }

    T ret = dfs(0, 1 << N);
    cout << max({ret.v1, ret.v2, ret.v3}) + 1 << "\n";
}