#include <bits/stdc++.h>

using namespace std;


int main()
{
    string m[110];
    int n,k;
    cin>>n>>k;
    string s;

    for (int i=1; i<=n; i++)
    {
        cin>>s;
        m[i]='-'+s+'-';
    }

    int ans=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<m[i].length(); j++)
        {
            if (m[i][j]=='S')
            {
                if ((m[i][j-1]=='P') or (m[i][j-1]=='S'))
                    {
                        ans+=1;
                    }
                if ((m[i][j+1]=='P') or (m[i][j+1]=='S'))
                    {
                        ans+=1;
                    }
            }
            if (k>0)
            if (m[i][j]=='.')
            {
                if ((m[i][j-1]!='S') and (m[i][j+1]!='S'))
                {
                    k--;
                    m[i][j]='x';
                }
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
    for (int j=1; j<m[i].length(); j++)
        if (k>0)
            if (m[i][j]=='.')
            {
                if ((m[i][j-1]!='S') or (m[i][j+1]!='S'))
                {
                    k--;
                    ans++;
                    m[i][j]='x';
                }
            }
    }
    for (int i=1; i<=n; i++)
    {
    for (int j=1; j<m[i].length(); j++)
        if (k>0)
            if (m[i][j]=='.')
            {
                    k--;
                    ans+=2;
                    m[i][j]='x';
            }
    }
    cout<<ans<<"\n";
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<m[i].length()-1; j++)
            cout<<m[i][j];
        cout<<"\n";
    }
    return 0;
}