#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

void solve()
{
    string S;
    cin >> S;
    set<char> s;
    int suc = 1;
    FOR(i, 1, S.length())
    {
        if (S[i] != S[i - 1])
        {
            if (suc % 2)
            {
                s.insert(S[i - 1]);
            }
            suc = 1;
        }
        else suc++;
    }
    if (suc % 2) s.insert(S.back());

    for (auto c : s) cout << c;
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    REP(_, T) solve();
}