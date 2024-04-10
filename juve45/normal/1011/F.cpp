#include <bits/stdc++.h>

using namespace std;

#define MAX 1000005

int no[MAX],ch[2][MAX], op[MAX],l,r, change[MAX];

void dfs(int nod)
{
    if (op[nod]==0)
        return;
    else if (op[nod]=='N')
    {
        dfs(ch[0][nod]);
        no[nod]=1-no[ch[0][nod]];
    }
    else
    {
        dfs(ch[0][nod]);
        dfs(ch[1][nod]);
        if (op[nod]=='O')
            no[nod]=no[ch[0][nod]]||no[ch[1][nod]];
        else if (op[nod]=='X')
            no[nod]=no[ch[0][nod]]!=no[ch[1][nod]];
        else
            no[nod]=no[ch[0][nod]]&&no[ch[1][nod]];
    }
}

void df(int nod)
{
    if (op[nod]==0)
    change[nod]=1;
    else if (op[nod]=='N')
        df(ch[0][nod]);
    else if (op[nod]=='A')
    {
        if (no[ch[0][nod]]==1)
        {
            if (no[ch[1][nod]]==0)
                df(ch[1][nod]);
            else {
                df(ch[1][nod]);
                df(ch[0][nod]);
            }
        }
        else if (no[ch[1][nod]]==1)
            df(ch[0][nod]);
    }
    else if (op[nod]=='X')
    {
        df(ch[1][nod]);
        df(ch[0][nod]);
    }
    else
    {
        if (no[ch[0][nod]]==0)
        {
            if (no[ch[1][nod]]==0)
                df(ch[0][nod]);
            df(ch[1][nod]);
        }
        else if (no[ch[1][nod]]==0)
            df(ch[0][nod]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if (s=="IN")
        {
            cin>>no[i];
        }
        else
        {
            op[i] = s[0];
            if (op[i]=='N')
                cin>>ch[0][i];
            else cin>>ch[0][i]>>ch[1][i];
        }
    }
    dfs(1);
    df(1);
    for (int i=1;i<=n;i++)
        if (op[i]==0)
    {
//        cout<<change[i];
        if (change[i]==1)
            cout<<1-no[1];
        else cout<<no[1];
    }
}