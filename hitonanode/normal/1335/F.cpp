#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;


void solve()
{
    int N, M;
    cin >> N >> M;
    string C, S;
    for (int i = 0; i < N; i++)
    {
        string c;
        cin >> c;
        C += c;
    }
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        S += s;
    }

    vector<int> nxt(S.length());
    for (int i = 0; i < nxt.size(); i++)
    {
        if (S[i] == 'U') nxt[i] = i - M;
        if (S[i] == 'D') nxt[i] = i + M;
        if (S[i] == 'L') nxt[i] = i - 1;
        if (S[i] == 'R') nxt[i] = i + 1;
    }

    for (int d = 0; d < 22; d++)
    {
        vector<int> nxnx = nxt;
        for (int i = 0; i < nxt.size(); i++)
        {
            nxnx[i] = nxt[nxt[i]];
        }
        nxt = nxnx;
    }
    vector<int> cnt(nxt.size()), cnt_black(nxt.size());
    for (int i = 0; i < nxt.size(); i++)
    {
        cnt[nxt[i]] = 1;
        if (C[i] == '0') cnt_black[nxt[i]] = 1;
    }
    printf("%d %d\n", accumulate(cnt.begin(), cnt.end(), 0), accumulate(cnt_black.begin(), cnt_black.end(), 0));
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int TC;
    cin >> TC;
    while (TC--)
    {
        solve();
    }
}