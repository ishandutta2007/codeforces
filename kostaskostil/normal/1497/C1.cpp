#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    while(___--)
    {
        int n, k;
        cin>>n>>k;
        while (k>3)
            cout<<1<<" ", k--, n--;

        int t = 1;
        while (n%(2*t) == 0)
            t*=2;
        if (t!=n)
            cout<<t<<" "<<(n-t)/2<<" "<<(n-t)/2<<"\n";
        else
            cout<<t/2<<" "<<t/4<<" "<<t/4<<"\n";

    }
}