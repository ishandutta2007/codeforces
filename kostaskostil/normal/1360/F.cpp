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
        int n,k;
        cin>>n>>k;
        vector<string> v(n);
        for (int i=0; i<n; i++)
            cin>>v[i];
        string ans="-1";
        for (int i=0; i<k; i++)
            for (char c='a'; c<='z'; c++)
        {
            string s=v[0];
            s[i]=c;
            bool ok=true;
            for (int j=1; j<n; j++)
            {
                int diff=0;
                for (int t=0; t<k; t++)
                    if (s[t]!=v[j][t])
                        diff++;
                if (diff>1)
                    ok=false;
            }
            if (ok)
                ans=s;
        }
        cout<<ans<<"\n";
    }
}