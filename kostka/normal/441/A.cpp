#include "bits/stdc++.h"

using namespace std;

set <int> S;

int main()
{
    int n, v;
    scanf("%d%d", &n, &v);
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        for(int j=0; j<a; j++)
        {
            int x;
            scanf("%d", &x);
            if(x<v)
                S.insert(i+1);
        }
    }
    printf("%d\n", (int)S.size());
    for(set<int>::iterator it = S.begin(); it != S.end(); it++)
        printf("%d ", *it);
    return 0;
}