#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt=0;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n;
        cin>>n;
        vector<string> v(n);
        for (int i=0; i<n; i++)
        {
            cin>>v[i];
        }
        bool good=true;
        for (int i=n-2; i>=0; i--)
            for (int j=n-2; j>=0; j--)
                if (v[i][j]=='1')
        if (v[i+1][j]=='0')
            if (v[i][j+1]=='0')
                good=false;
        if (good)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}