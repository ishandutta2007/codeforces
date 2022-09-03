#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


void solve()
{
    int N;
    string S;
    cin >> N >> S;
    vector<pair<string, int>> VS;
    FOR(l, 1, N + 1) {
        int times = N - l + 1;
        string s = S.substr(l - 1);
        string T = S.substr(0, l - 1);
        if (times % 2) reverse(T.begin(), T.end());
        VS.emplace_back(s + T, l);
    }
    auto itr = min_element(VS.begin(), VS.end());
    printf("%s\n", itr->first.c_str());
    printf("%d\n", itr->second);
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}