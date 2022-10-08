#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n, k, maks=0, ans;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        if((a+k-1)/k >= maks)
        {
            ans = i;
            maks = (a+k-1)/k;
        }
    }
    printf("%d\n", ans+1);
    return 0;
}