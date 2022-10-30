#include<bits/stdc++.h>

using namespace std;

struct node
{
    string dir;
    int num;
}ans[100005],ans2[100005];  //

int a[105][105];  //
int a2[105][105];
int n,m,anscnt,anscnt2;

bool chk1_1(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(a[x][i]==0)
        {
            return false;
        }
    }    
    return true;
}  //a[x]

bool chk1_2(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(a2[x][i]==0)
        {
            return false;
        }
    }    
    return true;
}	//a2[x]
 
bool chk2_1(int y)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i][y]<=0)
        {
            return false;
        }
    }
    return true;
}	//a[y]

bool chk2_2(int y)
{
    for(int i=1;i<=n;i++)
    {
        if(a2[i][y]<=0)
        {
            return false;
        }
    }
    return true;
}  //a2[y]

void chkrow(int x)
{
    while(chk1_1(x))
    {
        ans[anscnt].dir="row";
        ans[anscnt].num=x;
        anscnt++;
        for(int i=1;i<=m;i++)
        {
            a[x][i]--;
        }
    }
}  //a

void chkrow2(int x)
{
    while(chk1_2(x))
    {
        ans2[anscnt2].dir="row";
        ans2[anscnt2].num=x;
        anscnt2++;
        for(int i=1;i<=m;i++)
        {
            a2[x][i]--;
        }
    }
}	//a2

void chkcol(int y)
{
    while(chk2_1(y))
    {
        ans[anscnt].dir="col";
        ans[anscnt].num=y;
        anscnt++;
        for(int i=1;i<=n;i++)
        {
            a[i][y]--;
        }
    }
}	//a

void chkcol2(int y)
{
    while(chk2_2(y))
    {
        ans2[anscnt2].dir="col";
        ans2[anscnt2].num=y;
        anscnt2++;
        for(int i=1;i<=n;i++)
        {
            a2[i][y]--;
        }
    }
}	//a2

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            a2[i][j]=a[i][j];
        }
    }	//
    for(int i=1;i<=n;i++)
    {
        chkrow(i);
    }
    for(int i=1;i<=m;i++)
    {
        chkcol(i);
    }	//a

    for(int i=1;i<=m;i++)
    {
        chkcol2(i);
    }
    for(int i=1;i<=n;i++)
    {
        chkrow2(i);
    }	//a2
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]!=0)
            {
                cout<<"-1"<<endl;
                exit(0);
            }
        }
    }	//0-1
    if(anscnt<=anscnt2)	//
    {
        cout<<anscnt<<endl;
        for(int i=0;i<anscnt;i++)
        {
            cout<<ans[i].dir<<' '<<ans[i].num<<endl;
        }
    }
    else
    {
        cout<<anscnt2<<endl;
        for(int i=0;i<anscnt2;i++)
        {
            cout<<ans2[i].dir<<' '<<ans2[i].num<<endl;
        }        
    }
    
    return 0;
}