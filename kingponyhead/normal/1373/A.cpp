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
        int a, b, c;
        cin >> a >> b >> c;
        int ra = -1, rb = -1;
        if (1LL * a * b < c)
            ra = b;
        if (1LL * a * b > c)
            rb = b;
        if (a < c)
            ra = 1;
        if (a > c)
            rb = 1;
        printf("%d %d\n", ra, rb);
    }
    return 0;
}