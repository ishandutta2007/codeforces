#include <bits/stdc++.h>

using namespace std;

int a[120], n, b[120];
char c;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c, a[i]=c-'0';

    for(int i=1;i<=n;i++)
        cin>>c, b[i]=c-'0';

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    if(a[1] < b[1])
    {
    for(int i=2;i<=n;i++)
        if(a[i] >= b[i])
        {
            cout<<"NO\n";
            return 0;
        }
        cout<<"YES\n";
        return 0;
    }

    if(a[1] > b[1])
    {
    for(int i=2;i<=n;i++)
        if(a[i] <= b[i])
        {
            cout<<"NO\n";
            return 0;
        }
        cout<<"YES\n";
        return 0;
    }

    cout<<"NO\n";

    return 0;
}