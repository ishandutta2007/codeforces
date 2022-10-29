// Ponies everywhere ...
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int n, m, q, A[N], R[N];
bool M[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &A[i]), R[A[i]] = i, M[i] = 0;
        int mn = 1, mx = n, Cn = 0;
        for (int i = n; i > 1; i --)
        {
            if (R[i] == mx)
                {Cn = 1; break;}
            if (R[i] == mn)
                {Cn = -1; break;}
            M[R[i]] = 1;
            while (M[mx]) mx --;
            while (M[mn]) mn ++;
        }
        assert(Cn != 0);
        puts(Cn == 1 ? "YES" : "NO");
    }
    return 0;
}