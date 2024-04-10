// Criminal.
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 19, Mod = 1e9 + 7;
int n, m, q, A[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
            swap(a, b);
        int cnt = 0;
        while (b <= c)
        {
            a += b;
            swap(a, b);
            cnt ++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}