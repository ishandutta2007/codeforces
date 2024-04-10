#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> cnt(K + 1);
    vector<int> M;
    while (N--)
    {
        int m;
        cin >> m;
        cnt[m]++;
        M.emplace_back(m);
    }
    int nb = 1;
    vector<int> C(K);
    cin >> C;
    int acc = 0;
    IREP(k, K)
    {
        acc += cnt[k + 1];
        chmax(nb, (acc + C[k] - 1) / C[k]);
    }
    vector<vector<int>> ans(nb);
    sort(M.rbegin(), M.rend());
    int i = 0;
    for (auto m : M)
    {
        int j = i % (2 * nb);
        if (j >= nb) j = 2 * nb - 1 - j;
        ans[j].emplace_back(m);
        i++;
    }
    cout << nb << '\n';
    for (auto x : ans)
    {
        cout << x.size();
        for (auto v : x) cout << ' ' << v;
        cout << '\n';
    }
}