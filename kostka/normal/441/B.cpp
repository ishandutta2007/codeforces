#include "bits/stdc++.h"

using namespace std;

priority_queue <pair <int, int> > Q;

int dni[3007];

int main()
{
    long long wyn = 0;
    int n, v;
    scanf("%d%d", &n, &v);
    for(int i=1; i<=3001; i++)
        dni[i] = v;
    for(int i=0; i<n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Q.push(make_pair(-a,b));
    }
    while(!Q.empty())
    {
        pair <int, int> tmp = Q.top();
        tmp.first *= -1;
        Q.pop();
        int ile1 = min(dni[tmp.first], tmp.second);
        dni[tmp.first] -= ile1;
        tmp.second -= ile1;
        wyn += ile1;
        int ile2 = min(dni[tmp.first+1], tmp.second);
        dni[tmp.first+1] -= ile2;
        tmp.second -= ile2;
        wyn += ile2;
    }
    printf("%lld\n", wyn);
    return 0;
}