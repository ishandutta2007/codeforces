#include <iostream>
#define DMAX 505
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, ok, a[DMAX][DMAX];
    int l=1;

void dfs(int x, int y, int& lvl)
{
    a[x][y]=-1;
    if(lvl>ok)
        a[x][y]=2;

    for(int i=0; i<4; i++)
    {
        if(a[x+dx[i]][y+dy[i]]==0)
            dfs(x+dx[i], y+dy[i], ++lvl);
    }
}

void bord()
{
    for(int i=0; i<=n; i++)
    {
        a[i][0]=1;
        a[i][m+1]=1;
    }

    for(int i=0; i<=m; i++)
    {
        a[0][i]=1;
        a[n+1][i]=1;
    }
}

void print()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            switch (a[i][j])
            {
            case -1 :
                cout<<'.';
                break;
            case 1 :
                cout<<'#';
                break;
            case 2 :
                cout<<'X';
                break;
            }
        }
        cout<<'\n';
    }
}

int main()
{
    cin>>n>>m>>ok;
    int ax=0, ay=0, c=0;
    char k;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            cin>>k;
            if(k=='.')
                a[i][j]=0;
            if(k=='#')
                a[i][j]=1;
            if(k=='.')
            {
                c++;
                if(ax==0)
                ax=i, ay=j;
            }
        }
    ok=c-ok;
    bord();
    dfs(ax, ay, l);
    print();

    return 0;
}