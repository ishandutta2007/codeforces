#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define int long long
#define fi first
#define se second

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int a;
    int b;
    a=0;
    b=0;
    int w, h;
    cin>>n;
    string s;
    for (int i=0; i<n; i++)
    {
        cin>>s>>w>>h;
        if (w<h)
            swap(w, h);
        if (s=="+")
        {
            a=max(a, w);
            b=max(b, h);
        }
        else
        {
            if ((a<=w) and (b<=h))
            cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}