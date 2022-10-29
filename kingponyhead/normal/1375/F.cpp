// Ponies everywhere ...
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector < ll > A(3);
    scanf("%lld%lld%lld", &A[0], &A[1], &A[2]);
    printf("First\n");
    fflush(stdout);

    vector < ll > V = A;
    sort(V.begin(), V.end(), greater < ll >());

    ll val = V[0] + V[0] - V[1] - V[2];
    printf("%lld\n", val);
    fflush(stdout);
    int i; scanf("%d", &i); i --;

    if (A[i] == V[0])
    {
        A[i] += val;
        V = A; sort(V.begin(), V.end(), greater < ll >());
        val = V[0] + V[0] - V[1] - V[2];
        printf("%lld\n", val);
        fflush(stdout);
        scanf("%d", &i); i --;
    }

    assert(A[i] != V[0]);
    if (A[i] == V[1]) val = V[0] - V[2];
    else val = V[0] - V[1];
    printf("%lld\n", val);
    fflush(stdout);

    return 0;
}