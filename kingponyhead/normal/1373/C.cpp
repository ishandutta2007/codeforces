// Screw this ..
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int n, q, m, A[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {
        string S;
        cin >> S;
        n = (int)S.size();
        int ps = 0, mn = 0, id = -1;
        long long tot = 0;
        for (int i = 0; i < n; i ++)
        {
            ps += (S[i] == '+') ? 1 : -1;
            if (ps < mn)
            {
                tot += (abs(ps) - abs(mn)) * 1LL * (i + 1);
                mn = ps, id = i;
            }
        }
        printf("%lld\n", tot + n);
    }
    return 0;
}