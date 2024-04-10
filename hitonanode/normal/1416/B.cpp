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
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

void solve()
{
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    lint tot = accumulate(ALL(A), 0LL);
    if (tot % N)
    {
        cout << "-1\n";
        return;
    }
    if (A == vector<lint>(N, A[0]))
    {
        cout << "0\n";
        return;
    }

    vector<pair<pint, lint>> ret;

    const lint tgt = tot / N;

    vector<plint> prov2i, req2i;
    FOR(i, 1, N)
    {
        // lint mod = A[i] % (i + 1);
        lint md = ((i + 1) - A[i] % (i + 1)) % (i + 1);
        if (md) req2i.emplace_back(md, i);
        lint x = A[i] / (i + 1);
        if (x) prov2i.emplace_back(x * (i + 1), i);
    }
    sort(prov2i.rbegin(), prov2i.rend());
    int ip = 0;
    sort(req2i.begin(), req2i.end());

    auto proc = [&](int i, int j, lint x) {
        if (i == j) return;
        if (!x) return;
        ret.emplace_back(pint(i, j), x);
        A[i] -= x * (i + 1);
        A[j] += x * (i + 1);
    };

    dbg(prov2i);
    for (auto [_, i] : req2i)
    {
        if (A[0] >= N - 1) break;
        lint md = ((i + 1) - A[i] % (i + 1)) % (i + 1);
        if (A[i] % (i + 1))
        {
            while (ip < int(prov2i.size()) and A[0] < md)
            {
                int j = prov2i[ip].second;
                if (j != i)
                {
                    lint f = A[j] / (j + 1);
                    if (f) proc(j, 0, f);
                }
                ip++;
            }
            if (A[0] < md) break;
            proc(0, i, md);
        }
        proc(i, 0, A[i] / (i + 1));
    }
    dbg(A);
    vector<plint> f2i;
    FOR(i, 1, N) f2i.emplace_back(-A[i], i);
    sort(f2i.begin(), f2i.end());

    for (auto [f, i] : f2i)
    {
        if (A[i] > tgt)
        {
            lint md = ((i + 1) - (A[i] - tgt) % (i + 1)) % (i + 1);
            proc(0, i, md);
            proc(i, 0, (A[i] - tgt) / (i + 1));
        }
        lint req = tgt - A[i];
        if (req < 0) continue;
        proc(0, i, req);
    }
    dbg(A);

    if (ret.size() > 3 * N or A != vector<lint>(N, A[0]))
    {
        cout << "-1\n";
        return;
    }
    cout << ret.size() << '\n';
    for (auto [p, x] : ret)
    {
        cout << p.first + 1 << ' ' << p.second + 1 << ' ' << x << '\n';
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}