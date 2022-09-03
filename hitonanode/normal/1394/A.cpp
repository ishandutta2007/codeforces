#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

vector<lint> S(vector<lint> a)
{
    int N = a.size();
    vector<lint> ret(N + 1);
    REP(i, N) ret[i + 1] = ret[i] + a[i];
    return ret;
}
int main()
{
    int N, D, M;
    cin >> N >> D >> M;
    vector<lint> Au, Ao;
    REP(_, N)
    {
        lint a;
        cin >> a;
        (a <= M ? Au : Ao).emplace_back(a);
    }
    sort(Ao.begin(), Ao.end());
    sort(Au.begin(), Au.end());
    const vector<lint> AAu = S(Au), AAo = S(Ao);
    dbg(Au);
    dbg(AAu);
    dbg(Ao);
    dbg(AAo);

    lint ret = 0;
    REP(i, Ao.size() + 1)
    {
        if (i and N - i < 1LL * (i - 1) * D) continue;
        int n_el = (i - 1) * D;
        int el_u = max<int>(n_el - (Ao.size() - i), 0);
        if (el_u > Au.size()) continue;
        ret = max(ret, AAo.back() - AAo[AAo.size() - 1 - i] + AAu.back() - AAu[el_u]);
    }
    cout << ret << '\n';
}