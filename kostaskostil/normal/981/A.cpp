#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int mx=0;
    for (int l=0; l<s.length(); l++)
        for (int r=l+1; r<s.length(); r++)
    {
        int q=0;
        for (int i=l; i<=r; i++)
            if (s[i]!=s[r+l-i])
                q=1;
        if (q==1)
            mx=max(mx,r-l+1);
    }
    cout<<mx<<"\n";
    return 0;
}