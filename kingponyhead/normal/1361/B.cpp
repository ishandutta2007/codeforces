// P-Pied!
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int n, m, q, A[N], C[N];
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1LL * a * a % Mod)
        if (b & 1) ret = 1LL * ret * a % Mod;
    return (ret);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {

        int p;
        cin >> n >> p;
        vector < int > V;
        for (int i = 1; i <= n; i ++)
        {
            int a;
            cin >> a;
            V.push_back(a);
            C[a] ++;
        }
        if (p == 1)
        {
            if (n & 1)
                printf("1\n");
            else
                printf("0\n");
            for (int i : V)
                C[i] = 0;
            continue;
        }
        sort(V.begin(), V.end());
        V.resize(unique(V.begin(), V.end()) - V.begin());
        int tot = 0;
        bool fail = 0, ff = 0;
        pair < int , int > nw = {0, 0};
        for (int j = (int)V.size() - 1; ~ j; j --)
        {
            int i = V[j];
            if (fail)
            {
                tot = (tot - 1LL * C[i] * Power(p, i) % Mod + Mod) % Mod;
                continue;
            }
            if (nw == make_pair(0, 0))
            {
                if (C[i] & 1)
                    nw = make_pair(i, 1);
                continue;
            }
            int cnt = 0;
            while (cnt < nw.first - i && nw.second * 1LL * p <= (long long)(1e7))
                nw.second *= p, cnt ++;
            if (cnt < nw.first - i)
            {
                fail = 1;
                tot = nw.second * 1LL * Power(p, nw.first - i - cnt + i) % Mod;
                tot = (tot - 1LL * C[i] * Power(p, i) % Mod + Mod) % Mod;
                continue;
            }
            ff = 1;
            nw.first = i;
            if (C[i] < nw.second)
            {
                nw.second -= C[i];
            }
            else if (C[i] == nw.second)
            {
                nw = make_pair(0, 0);
                assert(fail == 0);
                ff = 0;
            }
            else
            {
                nw.second = (C[i] - nw.second) & 1;
            }
        }
        if (!fail && ff)
        {
            tot = 1LL * nw.second * Power(p, nw.first) % Mod;
        }
        else if (!fail)
        {
            nw.second &= 1;
            if (nw.second)
                tot = (tot + Power(p, nw.first)) % Mod;
        }
        printf("%d\n", tot);
        for (int i : V)
            C[i] = 0;
    }
    return 0;
}