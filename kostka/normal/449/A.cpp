#include "bits/stdc++.h"

using namespace std;

vector <int> X;

int main()
{
    long long wyn = 0;
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    X.push_back(0);
    X.push_back(k);
    X.push_back(1);
    X.push_back(k-1);
    X.push_back(k-n+1);
    X.push_back(k-n);
    X.push_back(k-n-1);
    X.push_back(k-m+1);
    X.push_back(k-m-1);
    X.push_back(k-m);
    for(int i=0; i<X.size(); i++)
    {
        if(0 <= X[i] && X[i] <= k)
        {
            int x = n/(X[i]+1);
            int y = m/(k-X[i]+1);
            wyn = max(wyn, 1LL*x*y);
            x = n/(k-X[i]+1);
            y = m/(X[i]+1);
            wyn = max(wyn, 1LL*x*y);
        }
        //printf("%d %d\n", i, 1LL*x*y);
    }
    if(wyn==0)
        printf("-1\n");
    else
        printf("%lld\n", wyn);
}