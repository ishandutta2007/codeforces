#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

set<int> ans(int a, int b)
{
    int n = a + b;
    int al = (n + 1) / 2;
    int bo = n / 2;
    set<int> v;
    for (int i=0; i<=al; i++)
    {
        int j = a - i;
        if (j>=0)
            if (j<=bo)
        {
            v.insert(j + (al - i));
        }
    }
    return v;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
    {
        int a,  b;
        cin>>a>>b;
        set<int> a1, b1;
        a1 = ans(a, b);
        b1 = ans(b, a);
        for (int i : b1)
            a1.insert(i);
        cout<<a1.size()<<"\n";

        for (int i : a1)
            cout<<i<<" ";
        cout<<"\n";
    }
}