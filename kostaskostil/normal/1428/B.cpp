#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=500500;
typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _=0; _<___; _++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool r1=true, r2=true;
        for (char c:s)
            if (c=='<')
                r1=false;
            else if (c=='>')
                r2=false;
        if (r1 or r2)
        {
            cout<<n<<"\n";
        }
        else
        {
            int ans=0;
            for (int i=0; i<n; i++)
            {
                char c1=s[i];
                char c2=s[(i+1)%n];
                if ((c1=='-') or (c2=='-'))
                    ans++;
            }
            cout<<ans<<"\n";
        }
    }
}