#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long
//#define double long double

#define y0 y___0
#define y1 y___1

#define fi first
#define se second
#define pb push_back

#define timer (clock()*1.0/CLOCKS_PER_SEC)
#define e 0.000000000000000001

using namespace std;

main()
{

        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);
    vector<int> ans;
    int n;
    int s=0;
    int c=0;
    int x, a;
    cin>>n;
    cin>>a;
    s+=a;
    c+=a;
    ans.pb(1);
    for (int i=2; i<=n; i++)
        {
            cin>>x;
            s+=x;
            if (2*x<=a)
                c+=x, ans.pb(i);
        }
    if (2*c>s)
    {
        cout<<ans.size()<<"\n";
        for (int i:ans)
            cout<<i<<" ";
    }
    else
        cout<<"0\n";
}