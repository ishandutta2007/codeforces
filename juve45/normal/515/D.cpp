#include <bits/stdc++.h>
#define DMAX 2015
#define x first
#define y second
using namespace std;

int n, m, a[DMAX][DMAX];
int gr[DMAX][DMAX];
queue <pair<int, int> > q;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

void border()
{
    for(int i=1;i<=n;i++)
    {
        a[i][0]=1;
        a[i][m+1]=1;
    }

    for(int i=1;i<=m;i++)
    {
        a[0][i]=1;
        a[n+1][i]=1;
    }
}

void check_gr()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j]==0)
            {
            for(int k=0;k<4;k++)
                gr[i][j]+=(1-a[i+dx[k]][j+dy[k]]);

            if(gr[i][j]==1)
                q.push({i,j});
            }
}

void scad_grad(int x, int y)
{
    for(int i=0;i<4;i++)
    {
        if(gr[x+dx[i]][y+dy[i]]>0)
            gr[x+dx[i]][y+dy[i]]--;
        if(gr[x+dx[i]][y+dy[i]]==1)
            q.push({x+dx[i],y+dy[i]});
    }
}

void fill_a(int x, int y, int i, int j)
{

    // < 2
    // > 3
    // v 4
    // ^ 5
    if(x==i)
    {
        if(y<j)
            a[x][y]=2, a[i][j]=3;
        else
            a[x][y]=3, a[i][j]=2;
    }
    if(y==j)
    {
        if(x>i)
            a[x][y]=4, a[i][j]=5;
            else
                a[x][y]=5, a[i][j]=4;
    }
}

void toposort()
{

    while(!q.empty())
    {
        pair<int, int> p;
        p=q.front();
        q.pop();

        if(gr[p.x][p.y]==0) return;
        else gr[p.x][p.y]=0;

        for(int i=0;i<4;i++)
        {
            if(a[p.x+dx[i]][p.y+dy[i]]==0)
            {
                fill_a(p.x, p.y, p.x+dx[i],p.y+dy[i]);
                scad_grad(p.x+dx[i],p.y+dy[i]);
                break;
            }
        }
    }
}

bool check_blank()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j]==0)
            {
                cout<<"Not unique\n";
                return false;
            }
        return true;
}

void print()
{
    map <int, char> mp;
    mp[1]='*';
    mp[2]='<';
    mp[3]='>';
    mp[4]='v';
    mp[5]='^';
    for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            cout<<mp[a[i][j]];
            cout<<'\n';
        }

}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n>>m;
    char c;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            cin>>c;
            if(c=='*')
                a[i][j]=1;
            else a[i][j]=0;
        }

    border();
    check_gr();
    toposort();
    if(check_blank())
    print();

    return 0;
}