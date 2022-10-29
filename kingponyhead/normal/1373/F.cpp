// Screw this ..
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 2e6 + 9, Mod = 1e9 + 7;
int n, q, m, A[N], B[N];
ll PA[N], PB[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++)
            scanf("%d", &A[i]), A[i + n] = A[i];
        for (int i = 0; i < n; i ++)
            scanf("%d", &B[i]), B[i] = min(B[i], A[i] + A[i + 1]), B[i + n] = B[i];
        for (int i = 1; i <= n + n; i ++)
            PA[i] = PA[i - 1] + A[i - 1],
            PB[i] = PB[i - 1] + B[i - 1];

        bool Fail = 0;
        if (PB[n] < PA[n])
            Fail = 1;

        priority_queue < ll > Pq, Qp;
        for (int i = 1; i <= n + n && !Fail; i ++)
        {
            ll rval = PB[i] - PA[i];

            while (Pq.size() && Qp.size() && Pq.top() == Qp.top())
                Pq.pop(), Qp.pop();
            if (Pq.size() && Pq.top() > rval)
                {Fail = 1; break;}
            ll lval = PB[i - 1] - PA[i];
            Pq.push(lval);
            if (i >= n - 1)
            {
                int j = i - n + 2;
                ll llval = PB[j - 1] - PA[j];
                Qp.push(llval);
            }
        }
        if (Fail)
            {printf("NO\n"); continue;}
        printf("YES\n");
    }
    return 0;
}