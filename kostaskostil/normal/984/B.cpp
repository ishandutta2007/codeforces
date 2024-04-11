#include <bits/stdc++.h>

using namespace std;


int a[110][110];

main()
{
    int m,n;
    string s;
    cin>>m>>n;
    for (int i=1; i<=m; i++)
    {
        cin>>s;
        for (int j=1; j<=n; j++)
        {
            if (s[j-1]=='.')
                a[i][j]=0;
            else
                if (s[j-1]=='*')
                    a[i][j]=-1;
                else
                    a[i][j]=int(s[j-1]-'0');
        }
    }
    for (int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
    if (a[i][j]>=0)
    {
        int x=0;
        for (int k=-1; k<=1; k++)
            for (int p=-1; p<=1; p++)
            if ((k!=0) or (p!=0))
                if (a[i+k][j+p]==-1)
                    x++;
        if (x!=a[i][j])
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}