#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    if (n<=2)
    {
        cout<<1<<"\n";
        for (int i=1; i<=n; i++)
            cout<<1<<" ";
        cout<<"\n";
        return 0;
    }
    vector<int> p;
    p.resize(n+2);
    for (int i=2; i<=n+1; i++)
        if (p[i]==0)
            for (int j=2; i*j<=n+1; j++)
                p[i*j]=1;
    cout<<2<<"\n";
    for (int i=2; i<=n+1; i++)
        cout<<p[i]+1<<" ";
    cout<<"\n";
}