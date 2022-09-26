#include <bits/stdc++.h>
#pragma GCC optimize ("O3")

using namespace std;

int a[300500];

map<int, vector<int> > m;


main()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i], m[a[i]].push_back(i);
    for (auto pa:m)
    for (int i=pa.second[0]; i<pa.second[(pa.second.size())-1]; i++)
    {
        a[i]=-1;
    }
    long long ans=1;
    int f=0;
    for (int i=0; i<n; i++)
        if (a[i]!=-1)
        {
            if (f==0)
            {
                f=1;
                continue;
            }
            ans*=2, ans%=998244353;
        }
    cout<<ans<<"\n";
}