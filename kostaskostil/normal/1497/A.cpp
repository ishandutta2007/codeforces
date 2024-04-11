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
        int n;
        cin>>n;
        vector<int> v(n);
        map<int, int> a;

        for (int& i : v)
            cin>>i, a[i]++, i=1000*a[i]+i;
        sort(v.begin(), v.end());
        for (int i: v)
            cout<<i%1000<<" ";
        cout<<"\n";
    }
}