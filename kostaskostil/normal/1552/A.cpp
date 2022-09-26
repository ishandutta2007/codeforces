#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string t = s;
        sort(s.begin(), s.end());
        int k =0;
        for (int i=0; i<n; i++)
            if (s[i] != t[i])
                k++;
        cout<<k<<"\n";
    }
}