#include<bits/stdc++.h>
using namespace std;
bool odw[100005];
bool sas[3005][3005];
bool spec[100005];
vector<int> pol[100005];
vector<int> pol2[100005];
bool xd[100005];
int licz=0,licz2=1;
void dfs(int a,int maks)
{
    odw[a]=true;
    for(int x=1;x<=maks;x++)
        if(odw[x]==false&&sas[a][x]==false)
            dfs(x,maks);
}
void dfs2(int a)
{
    odw[a]=true;
    for(auto x:pol2[a])
    {
        if(spec[x]==false)
            licz2=0;
        if(odw[x]==false)
            dfs2(x);
    }
}
void solve1(int a,int b)
{
    int c,d;
    while(b--)
    {
        cin>>c>>d;
        sas[c][d]=true;
        sas[d][c]=true;
    }
    int licz=0;
    for(int x=1;x<=a;x++)
        if(odw[x]==false)
        {
            licz++;
            dfs(x,a);
        }
    cout<<licz-1;
}
void solve2(int a,int b)
{
    int c,d;
    while(b--)
    {
        cin>>c>>d;
        pol[c].push_back(d);
        pol[d].push_back(c);
    }
    for(int x=1;x<=a;x++)
    {
        if(pol[x].size()>=a-100)
        {
            spec[x]=true;
            for(auto y:pol[x])
                xd[y]=true;
            for(int y=1;y<=a;y++)
            {
                if(xd[y]==false)
                    pol2[x].push_back(y);
                xd[y]=false;
            }
        }
    }
    for(int x=1;x<=a;x++)
    {
        if(odw[x]==false&&spec[x]==true)
        {
            licz2=1;
            dfs2(x);
            licz+=licz2;
        }
    }
    cout<<licz;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(a<=3e3)
        solve1(a,b);
    else
        solve2(a,b);
	return 0;
}