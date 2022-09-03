#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios
{
    fast_ios()
    {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

vector<pint> ret;
string S;
void rev(int i, int j)
{
    ret.emplace_back(i, j);
    reverse(S.begin() + i, S.begin() + j + 1);
}

void solve()
{
    int N, K;
    cin >> N >> K;
    ret.clear();
    cin >> S;
    REP(i, N)
    {
        if (i < N / 2 - (K - 1))
        {
            if (S[i] == '(') continue;
        }
        else if (i < (N / 2 - (K - 1)) * 2)
        {
            if (S[i] == ')') continue;
        }
        else
        {
            if (i % 2 == 0 and S[i] == '(') continue;
            if (i % 2 == 1 and S[i] == ')') continue;
        }
        int j = i;
        while (S[j] == S[i]) j++;
        rev(i, j);
    }
    printf("%d\n", (int)ret.size());
    for (auto p : ret)
    {
        printf("%d %d\n", p.first + 1, p.second + 1);
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}