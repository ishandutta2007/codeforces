#include<bits/stdc++.h>
using namespace std;
char tab[105][105];
bool odw[105][105];
vector<pair<int,int>> ruchy;
vector<pair<int,int>> v;
bool pion=false;
bool poz=false;
bool xd=false;
bool xd1=false;
bool xd2=false;
void pre()
{
    for(int x=0;x<=103;x++)
        for(int y=0;y<=103;y++)
            tab[x][y]='*';
}
void dfs(int a,int b)
{
    odw[a][b]=true;
    int x=a,y=b;
    ruchy.push_back(make_pair(a,b));
    if(tab[a][b]=='F')
        xd=true;
    if(xd==true)
        return;
    if(tab[x-1][y]!='*'&&odw[x-1][y]==false)
        dfs(x-1,y);
    if(xd==true)
        return;
    if(tab[x+1][y]!='*'&&odw[x+1][y]==false)
        dfs(x+1,y);
    if(xd==true)
        return;
    if(tab[x][y-1]!='*'&&odw[x][y-1]==false)
        dfs(x,y-1);
    if(xd==true)
        return;
    if(tab[x][y+1]!='*'&&odw[x][y+1]==false)
        dfs(x,y+1);
    if(xd==true)
        return;
    ruchy.pop_back();
}
char conv(pair<int,int> p)
{
    if(pion==true)
        p.first*=(-1);
    if(poz==true)
        p.second*=(-1);
    if(p.first==0)
    {
        if(p.second==-1)
            return 'L';
        else
            return 'R';
    }
    else
    {
        if(p.first==-1)
            return 'U';
        else
            return 'D';
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int a,b;
    pre();
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
            cin>>tab[x][y];
    dfs(1,1);
    for(int x=0;x<ruchy.size()-1;x++)
        v.push_back(make_pair(ruchy[x+1].first-ruchy[x].first,ruchy[x+1].second-ruchy[x].second));
    pair<int,int> p1=make_pair(1,1),p2;
    for(auto x:v)
    {
        cout<<conv(x)<<'\n';
        fflush(stdout);
        cin>>p2.first>>p2.second;
        if((conv(x)=='L'||conv(x)=='R')&&xd1==false)
        {
            xd1=true;
            if(p1==p2)
            {
                poz=true;
                cout<<conv(x)<<'\n';
                fflush(stdout);
                cin>>p2.first>>p2.second;
            }
        }
        if((conv(x)=='U'||conv(x)=='D')&&xd2==false)
        {
            xd2=true;
            if(p1==p2)
            {
                pion=true;
                cout<<conv(x)<<'\n';
                fflush(stdout);
                cin>>p2.first>>p2.second;
            }
        }
        p1=p2;
    }
    return 0;
}