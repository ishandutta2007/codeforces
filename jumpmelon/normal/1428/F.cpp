#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int MAXN = 500000;
char S[MAXN + 2];
vector<pair<int, pair<int, int>>> A;
set<pair<int, int>> V;
map<pair<int, int>, int> L, R;

int main()
{
    // freopen("F.in", "r", stdin);
    int n;
    scanf("%d", &n);
    scanf("%s", S + 1);
    for (int i = 1; i <= n; i++)
        if (S[i] == '1')
        {
            if (S[i - 1] != '1')
                for (int p = i; p <= n; p++)
                {
                    if (S[p] != '1')
                        break;
                    A.push_back({p - i + 1, {i, p}});
                }
            if (S[i + 1] != '1')
                for (int p = i; p >= 1; p--)
                {
                    if (S[p - 1] != '1')
                        break;
                    A.push_back({i - p + 1, {p, i}});
                }
        }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    V.insert({0, 0});
    V.insert({n + 1, n + 1});
    for (auto &&p : A)
    {
        auto r = p.second;
        auto i = V.insert(r).first;
        R[r] = next(i)->second;
        L[r] = prev(i)->first;
    }
    big ans = 0;
    for (int i = 1; i <= n; i++)
        if (S[i] == '1')
        {
            if (S[i - 1] != '1')
                for (int p = i; p <= n; p++)
                {
                    if (S[p + 1] != '1')
                    {
                        ans += (big)(i - L[{i, p}]) * (R[{i, p}] - p) * (p - i + 1);
                        for (int l = 1; l < p - i; l++)
                            ans += (big)l * (p - i - l);
                        fprintf(stderr, "%d %d %lld\n", i, p, ans);
                        break;
                    }
                    ans += (big){i - L[{i, p}]} * (p - i + 1);
                    fprintf(stderr, "%d %d %lld\n", i, p, ans);
                }
            if (S[i + 1] != '1')
                for (int p = i; p >= 1; p--)
                {
                    if (S[p - 1] != '1')
                        break;
                    ans += (big)(R[{p, i}] - i) * (i - p + 1);
                    fprintf(stderr, "%d %d %lld\n", p, i, ans);
                }
        }
    printf("%lld\n", ans);
    return 0;
}