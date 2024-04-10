#include <bits/stdc++.h>
#define pb push_back
using namespace std;
char l='L',r='R',u='U',d='D';
char a[102][102];
long visi[102][102]={0};
pair < long , long > mv(long b)
{
    long x,y;
    if(b==0) cout<<u;
    if(b==1) cout<<d;
    if(b==2) cout<<l;
    if(b==3) cout<<r;
    cout<<endl;
    fflush(stdout);
    cin>>x>>y;
    return {x,y};
}
long f=0;
vector < pair <long ,long >  > v;
void dfs(long i,long j)
{
    visi[i][j]=1;
    if(a[i][j]=='F') {f=1;return;}
    if((a[i][j+1]=='.' || a[i][j+1]=='F') && visi[i][j+1]==0)
    {
        dfs(i,j+1);
        if(f==1)
        {v.pb({i,j+1});
        return;}
    }
    if((a[i-1][j]=='.' || a[i-1][j]=='F') && visi[i-1][j]==0)
    {
        dfs(i-1,j);
        if(f)
        {v.pb({i-1,j});return;}
    }
    if((a[i][j-1]=='.' || a[i][j-1]=='F')  && visi[i][j-1]==0)
    {
        dfs(i,j-1);
        if(f)
        {v.pb({i,j-1});return;}
    }
    if((a[i+1][j]=='.' || a[i+1][j]=='F') && visi[i+1][j]==0)
    {
        dfs(i+1,j);
        if(f)
        {v.pb({i+1,j});return;}
    }
}
int main()
{
    pair < long ,long > p;
    long n,m,i,j,x,y;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    cin>>a[i][j];
    if(a[1][2]=='.')
    {
        p=mv(3);
        if(p.first==1 && p.second==1) {r='L';l='R';}
        else p=mv(2);
        i=1;j=1;
        while(a[i+1][j]=='*')
        {
            p=mv(3);
            j++;
        }
        p=mv(1);
        if(p.first==i && p.second==j) {d='U';u='D';}
        else p=mv(0);
        while(j!=1)
        {
            p=mv(2);
            j--;
        }
    }
    else
    {
        p=mv(1);
        if(p.first==1 && p.second==1) {d='U';u='D';}
        else p=mv(0);
        i=1;j=1;
        while(a[i][j+1]=='*')
        {
            p=mv(1);
            i++;
        }
        p=mv(3);
        if(p.first==i && p.second==j) {r='L';l='R';}
        else p=mv(2);
        while(i!=1)
        {
            p=mv(0);
            i--;
        }
    }
    dfs(1,1);
    reverse(v.begin(),v.end());
    x=1,y=1;
    for(i=0;i<v.size();++i)
    {
        if(v[i].first>x)
        {
            mv(1);
            x=v[i].first;
        }
        else if(v[i].first<x)
        {
            mv(0);
            x=v[i].first;
        }
        if(v[i].second>y)
        {
            mv(3);
            y=v[i].second;
        }
        else if(v[i].second<y)
        {
            mv(2);
            y=v[i].second;
        }
    }
    return 0;
}