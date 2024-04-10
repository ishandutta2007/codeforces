// Criminal.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 19, Mod = 1e9 + 7;
int n, m, q, A[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long k;
    cin >> k;
    if (k == 1)
        return !printf("codeforces\n");
    if (k == 2)
        return !printf("codeforcess\n");
    string S = "codeforces";
    int a = 1;
    while (1)
    {
        ll z = 1;
        for (int i = 0; i < 10; i ++)
            z *= (ll)a;
        if (z >= k)
            break;
        a ++;
    }
    ll z = 1;
    for (int i = 0; i < 10; i ++)
        z *= (ll)a;
    assert(z >= k);
    int cnt = 0;
    while (z / a * (a - 1) >= k)
        cnt ++, z = z / a * (a - 1);
    for (int i = 0; i < 10; i ++)
    {
        int tt = a;
        if (i < cnt)
            tt = a - 1;
        for (int j = 0; j < tt; j ++)
            cout << S[i];
    }
    cout << endl;
    return 0;
}