#include <iostream>

using namespace std;

int m, n, a[101][101], b[101][101];

void put0(int l, int c)
{
    for(int i=1; i<=m; i++)
        a[l][i]=0;
    for(int i=1; i<=n; i++)
        a[i][c]=0;
}

bool search_c(int k)
{
    int i=1;
    while(i<=n)
    {
        if(b[i][k]!=1)
            return false;
        ++i;
    }
    return true;

}

bool search_l(int k)
{
    int i=1;
    while(i<=m)
    {
        if(b[k][i]!=1)
            return true;
        ++i;
    }
    for(int i=1; i<=m; i++)
    {
        if(search_c(i)==true)
        {
            if(a[k][i]==-1 || a[k][i]==1)
                a[k][i]=1;
            else if(a[k][i]==0)
            {
                cout<<"NO\n";
                return false;
            }
        }
    }
    return true;
}

bool check0(int l, int c)
{
    for(int i=1; i<=m; i++)
    {
        if(a[l][i]!=0)
            return false;
    }
    for(int i=1; i<=n; i++)
    {
        if(a[i][c]!=0)
            return false;
    }

    return true;
}


bool check1(int l, int c)
{
    for(int i=1; i<=m; i++)
    {
        if(a[l][i]==1)
            return true;
    }
    for(int i=1; i<=n; i++)
    {
        if(a[i][c]==1)
            return true;
    }
    return false;
}


int main()
{
    cin>>n>>m;


    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>b[i][j];


    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            a[i][j]=-1;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(b[i][j]==0)
                put0(i, j);

    for(int i=1; i<=n; i++)
        if(search_l(i)==false)
            goto loop;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j]==-1)
            {
                cout<<"NO\n";
                goto loop;
            }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(b[i][j]==0)
            {
                if(!check0(i, j))
                {
                    cout<<"NO\n";
                    goto loop;
                }
            }
            else if(!check1(i, j))
            {
                cout<<"NO\n";
                goto loop;
            }
        }


    cout<<"YES\n";
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
loop:
    return 0;
}