#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b)
{
    while ((a!=0) and (b!=0))
    {
        if (a>b)
            a%=b;
        else
            b%=a;
    }
    return max(a, b);
}

int n, m;
vector<int> g[100100];

void out()
{
    cout<<"Possible\n";
    for (int i=2; i<=n; i++)
        cout<<"1 "<<i<<"\n";
    for (int i=1; i<=n; i++)
        for (int j:g[i])
            cout<<i<<" "<<j<<"\n";
    exit(0);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    if (m<n-1)
    cout<<"Impossible\n", exit(0);
    m-=(n-1);
    if (m==0)
        out();
    for (int i=2; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            if (gcd(i, j)==1)
    {
        g[i].push_back(j);
        m--;
        if (m==0)
            out();
    }
    cout<<"Impossible\n", exit(0);
}