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
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;

        int y=x%14;
        if ((1<=y)
            and (y<=6)
               and (x>14))
               cout<<"YES\n";
            else
                cout<<"NO\n";

    }
}