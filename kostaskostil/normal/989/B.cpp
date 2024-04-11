#include <bits/stdc++.h>

using namespace std;

int main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,p;
    int s[2010];
    cin>>n>>p;
    for (int i=1; i<=n; i++)
    {
        char t;
        cin>>t;
        if (t=='1')
            s[i]=1;
        if (t=='0')
            s[i]=0;
        if (t=='.')
            s[i]=-1;
    }
    int c=0;
    for (int i=1; i<=n-p; i++)
    {
        if ((s[i]==-1) and (s[i+p]==-1))
            s[i]=0, s[i+p]=1;
        if (s[i]==-1)
            s[i]=1-s[i+p];
        if (s[i+p]==-1)
            s[i+p]=1-s[i];
        if (s[i+p]!=s[i])
            c=1;
    }
    if (c==0)
        cout<<"No\n";
    else
    {
        for (int i=1; i<=n; i++)
        {
            if (s[i]!=-1)
                cout<<s[i];
            else
            {
                cout<<"1";
            }
        }
    }
    return 0;
}