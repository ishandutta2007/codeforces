#include<bits/stdc++.h>
using namespace std;
set<int> polaczenia[5005];
int lider[5005];
int war[5005];
int wch[5005];
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
void pre(int a)
{
    for(int x=1;x<=a;x++)
        lider[x]=x;
}
bool czy=false;
bool odw[5005];
bool tmp[5005];
void dfs(int a)
{
    odw[a]=true;
    tmp[a]=true;
    for(auto x:polaczenia[a])
    {
        if(tmp[lider[x]]==true)
            czy=true;
        if(odw[lider[x]]==false)
            dfs(lider[x]);
    }
    tmp[a]=false;
}
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    char znak;
    pre(a+b+5);
    for(int x=1;x<=a;x++)
        for(int y=a+1;y<=a+b;y++)
        {
            cin>>znak;
            if(znak=='=')
                u(x,y);
            else if(znak=='>')
                polaczenia[y].insert(x);
            else
                polaczenia[x].insert(y);
        }
    for(int x=1;x<=a+b;x++)
        f(x);
    for(int x=1;x<=a+b;x++)
        if(lider[x]!=x)
            for(auto y:polaczenia[x])
                polaczenia[lider[x]].insert(y);
    for(int x=1;x<=a+b;x++)
        if(odw[x]==false&&lider[x]==x)
            dfs(x);
    for(int x=1;x<=a+b;x++)
        if(lider[x]==x)
            for(auto y:polaczenia[x])
                wch[lider[y]]++;
    if(czy==true)
    {
        cout<<"No";
        return 0;
    }
    for(int x=1;x<=a+b;x++)
        if(lider[x]==x&&wch[x]==0)
            q.push(x);
    int pom;
    while(q.empty()==false)
    {
        pom=q.front();
        q.pop();
        for(auto y:polaczenia[pom])
        {
            wch[lider[y]]--;
            if(wch[lider[y]]==0)
                q.push(lider[y]);
            war[lider[y]]=max(war[lider[y]],war[pom]+1);
        }
    }
    cout<<"Yes"<<'\n';
    for(int x=1;x<=a;x++)
        cout<<war[lider[x]]+1<<" ";
    cout<<'\n';
    for(int x=a+1;x<=a+b;x++)
        cout<<war[lider[x]]+1<<" ";
	return 0;
}