#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define pb push_back

//#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int t=0;
        cin>>t;
        if (t==1)
            cout<<-1<<"\n";
        else
        {
            for (int i=1; i<t; i++)
                cout<<7;
            cout<<"8\n";
        }
    }
    return 0;
}