#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int a[300];


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];

    for (int i=1; i<=1000; i++)
    {
        for (int j=1; j<n; j++)
        {
            if (a[j]>0)
                cout<<"P", a[j]--;
            cout<<"R";
        }
        for (int j=n; j>1; j--)
        {
            if (a[j]>0)
                cout<<"P", a[j]--;
            cout<<"L";
        }
    }

    return 0;
}