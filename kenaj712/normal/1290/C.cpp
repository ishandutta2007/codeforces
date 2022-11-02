#include<bits/stdc++.h>
using namespace std;
// 1e6+1 - zawsze off --- 1e6+2 - zawsze on
int wynik;
int zaw0=1e6+1,zaw1=1e6+2;
int lider[1000005];
int war0[1000005];
int war1[1000005];
bool state[1000005];
vector<int> pol[1000005];
vector<int> pol2[1000005];
bool odw[1000005];
vector<int> v;
void pre(int b)
{
    for(int x=1;x<=b;x++)
    {
        lider[x]=x;
        war0[x]=1;
    }
    war0[zaw0]=1e8;
    war0[zaw1]=1e8;
    state[zaw1]=true;
    lider[zaw0]=zaw0;
    lider[zaw1]=zaw1;
}
int f(int a)
{
    if(lider[a]!=a)
        lider[a]=f(lider[a]);
    return lider[a];
}
void u(int a,int b)
{
    lider[f(a)]=f(b);
}
void dfs(int a)
{
    v.push_back(a);
    odw[a]=true;
    state[a]=!state[a];
    for(auto x:pol2[a])
        if(odw[x]==false)
            dfs(x);
}
void zlacz(int a,int b,int c)
{
    if(f(a)==f(b))
        return;
    if((state[a] == state[b] && c==0) || (state[a]!=state[b] && c==1))
    {
        wynik-=min(war0[f(a)],war1[f(a)]);
        wynik-=min(war0[f(b)],war1[f(b)]);
        int war2=war0[f(a)]+war0[f(b)],war3=war1[f(a)]+war1[f(b)];
        wynik+=min(war2,war3);
        u(a,b);
        war0[f(a)]=war2;
        war1[f(a)]=war3;
    }
    else
    {
        if(war0[f(a)]+war1[f(a)]<war0[f(b)]+war1[f(b)])
        {
            dfs(a);
            swap(war0[f(a)],war1[f(a)]);
        }
        else
        {
            dfs(b);
            swap(war0[f(b)],war1[f(b)]);
        }
        wynik-=min(war0[f(a)],war1[f(a)]);
        wynik-=min(war0[f(b)],war1[f(b)]);
        int war2=war0[f(a)]+war0[f(b)],war3=war1[f(a)]+war1[f(b)];
        wynik+=min(war2,war3);
        u(a,b);
        war0[f(a)]=war2;
        war1[f(a)]=war3;
    }
    pol2[a].push_back(b);
    pol2[b].push_back(a);
    while(!v.empty())
    {
        odw[v.back()]=false;
        v.pop_back();
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,e,f,g;
    string d;
    cin>>a>>b>>d;
    for(int x=1;x<=b;x++)
    {
        cin>>e;
        while(e--)
        {
            cin>>f;
            pol[f].push_back(x);
        }
    }
    pre(b);
    for(int x=1;x<=a;x++)
    {
        if(pol[x].size()==0)
        {
            cout<<wynik<<'\n';
            continue;
        }
        g=0;
        if(pol[x].size()==1)
        {
            e=pol[x][0];
            if(d[x-1]=='0')
                f=zaw1;
            else
                f=zaw0;
        }
        else
        {
            if(d[x-1]=='0')
                g=1;
            e=pol[x][0];
            f=pol[x][1];
        }
        zlacz(e,f,g);
        cout<<wynik<<'\n';
    }
	return 0;
}