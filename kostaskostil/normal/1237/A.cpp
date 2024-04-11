#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define int long long

#define fi first
#define se second
#define pb push_back

using namespace std;

int tr(int x)
{
    if (x>0)
        return x/2;
    return x/2-1;
}
main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int s=0;
    int n;
    cin>>n;
    int x;
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        if (x%2==0)
            cout<<x/2<<"\n";
        else
        {
            if (s==0)
                s=1, cout<<signed(tr(x))<<"\n";
            else
                s=0, cout<<signed(tr(x)+1)<<"\n";
        }
    }

    return 0;
}