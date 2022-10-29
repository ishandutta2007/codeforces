// Ponies everywhere ...
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int n, m, q, A[N], B[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {
        cin >> n;
        for (int i = 1; i <= n; i ++)
        {
            cin >> A[i];
            if (i & 1) printf("%d ", abs(A[i]));
            else printf("%d ", - abs(A[i]));
        }
        printf("\n");
    }
    return 0;
}