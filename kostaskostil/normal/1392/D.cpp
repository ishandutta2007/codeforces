#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

int f(int l, int r)
{
//    cout<<l<<" "<<r<<"\n";
    return (l/3) + (r/3);

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    for (int iii=0; iii<qqq; iii++)
    {
        int n;
        string s;
        cin>>n>>s;
        int ans=0;
        bool ok=false;
        for (int i=0; i<n; i++)
            if (s[i]=='R' and s[(i+1)%n]=='L')
        {
            ok=true;
            int l=0;
            int r=0;
            int j=i;
            while (s[j]=='R')
                l++, j=(j+n-1)%n;
            j=(i+1)%n;
            while (s[j]=='L')
                r++, j=(j+1)%n;
            ans+=f(l, r);
        }
        if (!ok)
            ans=f(n-1, 1)+1;

        cout<<ans<<"\n";
    }

    return 0;
}