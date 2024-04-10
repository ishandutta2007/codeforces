#include<bits/stdc++.h>
using namespace std;
bool tab[205][205];
bool start[205][205];
void pre(int a,int b)
{
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
            tab[x][y]=start[x][y];
}
bool check(int a,int b)
{
    int licz[2];
    licz[0]=0;
    licz[1]=0;
    for(int x=0;x<b;x++)
        licz[tab[a][x]]++;
    if(licz[0]==0||licz[1]==0)
        return true;
    else
        return false;
}
bool check2(int a,int b)
{
    int licz=0;
    for(int x=0;x<b-1;x++)
        if(tab[a][x]!=tab[a][x+1])
            licz++;
    if(licz>1)
        return true;
    else
        return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
            cin>>start[x][y];
    pre(a,b);
    vector<int> v;
    vector<int> v2;
    v2.push_back(0);
    for(int x=0;x<b;x++)
    {
        if(tab[0][x]==1)
        {
            v.push_back(1);
            for(int y=0;y<a;y++)
                tab[y][x]=(!tab[y][x]);
        }
        else
            v.push_back(0);
    }
    int licz=0;
    for(int x=1;x<a;x++)
    {
        if(check(x,b)==true)
        {
            if(tab[x][0]==1&&licz==0||tab[x][0]==0&&licz==1)
                v2.push_back(1);
            else
                v2.push_back(0);
        }
        else
        {
            licz++;
            licz+=check2(x,b);
            if(tab[x][0]==1)
                v2.push_back(1);
            else
                v2.push_back(0);
        }
    }
    if(licz<2)
    {
        cout<<"YES"<<'\n';
        for(auto x:v2)
            cout<<x;
        cout<<'\n';
        for(auto x:v)
            cout<<x;
        return 0;
    }
    pre(a,b);
    v.resize(0);
    v2.resize(0);
    for(int x=0;x<b;x++)
    {
        if(tab[a-1][x]==0)
        {
            v.push_back(1);
            for(int y=0;y<a;y++)
                tab[y][x]=(!tab[y][x]);
        }
        else
            v.push_back(0);
    }
    licz=0;
    for(int x=0;x<a-1;x++)
    {
        if(check(x,b)==true)
        {
            if(tab[x][0]==1&&licz==0||tab[x][0]==0&&licz==1)
                v2.push_back(1);
            else
                v2.push_back(0);
        }
        else
        {
            licz++;
            licz+=check2(x,b);
            if(tab[x][0]==1)
                v2.push_back(1);
            else
                v2.push_back(0);
        }
    }
    v2.push_back(0);
    if(licz<2)
    {
        cout<<"YES"<<'\n';
        for(auto x:v2)
            cout<<x;
        cout<<'\n';
        for(auto x:v)
            cout<<x;
        return 0;
    }
    cout<<"NO";
	return 0;
}