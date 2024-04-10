// Screw this ..
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int n, q, m, A[N], B[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    set < int > ST;
    A[0] = 0;
    for (int i = 1; i <= n; i ++)
    {
        cin >> A[i];
        if (A[i] == A[i - 1])
        {
            ST.insert(i);
            continue;
        }
        int cnt = A[i - 1] + 1;
        B[i] = A[i - 1];
        while (cnt < A[i])
        {
            if (!ST.size())
                return !printf("-1\n");
            int j = * ST.begin();
            ST.erase(ST.begin());
            B[j] = cnt ++;
        }
    }
    if (ST.size())
        for (int i : ST)
            B[i] = 1e6 - 1;
    for (int i = 1; i <= n; i ++)
        printf("%d ", B[i]);
    return 0;
}