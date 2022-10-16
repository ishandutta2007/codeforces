#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);

    char S[10*N];

    unordered_map<int, int> M;

    ll res = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s", S+1);
        int l = strlen(S+1);
        int mask = 0;

        for(int j=1;j<=l;j++)
        {
            mask = mask ^ (1<<int(S[j]-'a'));
        }

        for(int j=0;j<='z'-'a';j++)
        {
            res += M[mask ^ (1<<j)];
        }

        res += M[mask];
        M[mask]++;
    }

    printf("%lld\n", res);
}