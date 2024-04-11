#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

#define int long long

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt=0;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int x, y;
        cin>>x>>y;
        if (x*y % 2 == 0)
            cout<<x*y/2<<"\n";
        else cout<<x*y/2+1<<"\n";
    }
}