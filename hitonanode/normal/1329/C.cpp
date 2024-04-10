#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


vector<int> A, dnow, dnxt, ok, depth;
int H, G;

void updD(int i) {
    if (!A[i]) dnow[i] = 0, dnxt[i] = -1, ok[i] = 0;
    else {
        if (i * 2 >= (1 << H)) dnow[i] = 1, dnxt[i] = 0;
        else {
            int l = i * 2, r = i * 2 + 1;
            dnow[i] = min(dnow[l], dnow[r]) + 1;
            if (!A[l] and !A[r]) dnxt[i] = 0;
            else if (A[l] > A[r]) dnxt[i] = min(dnxt[l], dnow[r]) + 1;
            else dnxt[i] = min(dnow[l], dnxt[r]) + 1;
        }
        if (dnxt[i] < depth[i] - H + G) ok[i] = 0;
    }
}

void f(int i) {
    int l = i * 2;
    int r = i * 2 + 1;
    if (l >= (1 << H)) {
        A[i] = 0;
    }
    else {
        if (A[l] > A[r]) {
            A[i] = A[l];
            f(l);
        }
        else {
            A[i] = A[r];
            if (A[r]) f(r);
        }
    }
    updD(i);
}

void solve()
{
    cin >> H >> G;
    A.assign(1 << H, 0);
    FOR(i, 1, 1 << H) cin >> A[i];
    dnow.resize(1 << H);
    depth.resize(1 << H);
    dnxt.resize(1 << H);
    ok.assign(1 << H, 1);
    FOR(i, 1, dnow.size()) depth[i] = dnow[i] = int(__builtin_clz(i)) - 31 + H;
    FOR(i, 1, dnow.size()) dnxt[i] = int(__builtin_clz(i)) - 32 + H;
    // dbg(depth);
    vector<int> ret_procedure((1 << H) - (1 << G));
    int x = 1;
    REP(t, ret_procedure.size()) {
        while (!ok[x]) x++;
        ret_procedure[t] = x;
        f(x);
        int now = x;
        while (now) {
            updD(now);
            now /= 2;
        }
    }
    lint ret = accumulate(A.begin(), A.end(), 0LL);
    printf("%lld\n", ret);
    for (auto x : ret_procedure) printf("%d ", x);
    puts("");
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}