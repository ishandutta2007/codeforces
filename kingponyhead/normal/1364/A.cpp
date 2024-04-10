// Screw this ..
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 9, Mod = 1e9 + 7;
int n, q, m, A[N], F[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {
        cin >> n >> m;
        int id = -1, Mx = -1;
        for (int i = 1; i <= n; i ++)
        {
            cin >> A[i];
            A[i] += A[i - 1];
            if (A[i] % m && id == -1)
                id = i;
            if (A[i] % m)
                Mx = max(Mx, i);
            else if (id != -1 && id != i)
                Mx = max(Mx, i - id);
        }
        printf("%d\n", Mx);
    }
    return 0;
}