#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<vector<int>> gcds;

int solve()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<int> cnt(26);
    for (auto c : S) cnt[c - 'a']++;
    IFOR(i, 2, N + 1)
    {
        int g = gcds[i][K];
        int nb = i / g;
        int ch = 0;
        for (auto x : cnt) ch += x / nb;
        if (ch >= g) return i;
    }
    return 1;
}

int main()
{
    gcds.assign(2001, vector<int>(2001));
    REP(i, gcds.size()) REP(j, gcds[i].size()) gcds[i][j] = __gcd(i, j);

    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}