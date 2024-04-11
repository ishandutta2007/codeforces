
#include <bits/stdc++.h>
#define int long long
using namespace std;

int st[100100];
int a1[100100];
int a2[100100];
main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,a,b;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        cin>>a>>b;
        st[a]++;
        st[b]++;
    }
    int c=0;
    for (int i=1; i<=n; i++)
        if (st[i]>2)
            c++;
    if (c>1)
    {
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    if (c==1)
    {
        int q,ans;
        for (int i=1; i<=n; i++)
            if (st[i]>2)
                q=i;
        ans=0;
        int l=1;
        for (int i=1; i<=n; i++)
            if (st[i]==1)
            {
                if (l==1)
                {
                    ans++;
                    a1[ans]=i;
                    l=2;
                }
                else
                {
                    a2[ans]=i;
                    l=1;
                }
            }
        if (l==2)
        {
            a2[ans]=q;
        }
        cout<<ans<<"\n";
        for (int i=1; i<=ans; i++)
            cout<<a1[i]<<" "<<a2[i]<<"\n";
    }
    if (c==0)
    {
        cout<<"1\n";
        for (int i=1; i<=n; i++)
            if (st[i]==1)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}