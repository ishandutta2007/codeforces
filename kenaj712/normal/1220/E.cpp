#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
bool odw[1000005];
bool zle[1000005];
bool spec[1000005];
bool mark[1000005];
queue<int> q;
int wch[1000005];
long long waga[1000005];
long long out=0;
vector<vector<int>> v;
vector<int> wtf;
long long maks=0,maks_global=0,maks_xd=0,do_speca,maks_lulz;
vector<int> v2;
void dfs(int a)
{
    odw[a]=true;
    wtf.push_back(a);
    for(auto x:pol[a])
        if(odw[x]==false&&zle[x]==true)
            dfs(x);
}
void czysc(int a)
{
    for(int x=1;x<=a;x++)
        odw[x]=false;
}
void dfs2(int a,long long b)
{
    odw[a]=true;
    maks=max(maks,b);
    for(auto x:pol[a])
        if(odw[x]==false&&zle[x]==true)
            dfs2(x,waga[x]+b);
}
void dfs3(int a,long long b)
{
    odw[a]=true;
    maks_xd=max(maks_xd,b);
    if(spec[a]==true)
        do_speca=b;
    for(auto x:pol[a])
        if(odw[x]==false&&zle[x]==true)
            dfs3(x,waga[x]+b);
}
void dfs4(int a)
{
    odw[a]=true;
    v2.push_back(a);
    if(spec[a]==true)
        for(auto x:v2)
            mark[x]=true;
    for(auto x:pol[a])
        if(odw[x]==false&&zle[x]==true)
            dfs4(x);
    v2.pop_back();
}
void dfs5(int a,long long b)
{
    odw[a]=true;
    maks_lulz=max(maks_lulz,b);
    for(auto x:pol[a])
        if(odw[x]==false&&zle[x]==true)
        {
            if(mark[x]==false)
                dfs5(x,waga[x]+b);
            else
                dfs5(x,b);
        }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        cin>>waga[x];
    while(b--)
    {
        cin>>c>>d;
        wch[c]++;
        wch[d]++;
        pol[c].push_back(d);
        pol[d].push_back(c);
    }
    for(int x=1;x<=a;x++)
        if(wch[x]==1)
            q.push(x);
    while(q.empty()==false)
    {
        int pom=q.front();
        q.pop();
        zle[pom]=true;
        for(auto x:pol[pom])
        {
            wch[x]--;
            if(wch[x]==1)
                q.push(x);
        }
    }
    for(int x=1;x<=a;x++)
        if(zle[x]==false)
            out+=waga[x];
    for(int x=1;x<=a;x++)
        if(zle[x]==true)
        {
            for(auto y:pol[x])
                if(zle[y]==false)
                    spec[x]=true;
        }
    for(int x=1;x<=a;x++)
    {
        if(odw[x]==false&&zle[x]==true)
        {
            dfs(x);
            v.push_back(wtf);
            wtf.resize(0);
        }

    }
    czysc(a);
    int start;
    cin>>start;
    if(zle[start]==false)
    {
        for(auto x:v)
        {
            for(auto y:x)
                if(spec[y]==true)
                    dfs2(y,waga[y]);
            maks_global=max(maks_global,maks);
            maks=0;
        }
        cout<<out+maks_global;
    }
    else
    {
        for(auto x:v)
        {
            bool czy=false;
            for(auto y:x)
                if(y==start)
                    czy=true;
            if(czy==false)
            {
                for(auto y:x)
                    if(spec[y]==true)
                        dfs2(y,waga[y]);
                maks_global=max(maks_global,maks);
                maks=0;
            }
            else
                dfs3(start,waga[start]);
        }
        czysc(a);
        for(auto x:v)
        {
            bool czy=false;
            for(auto y:x)
                if(y==start)
                    czy=true;
            if(czy==true)
            {
                dfs4(start);
                czysc(a);
                for(auto y:x)
                    if(spec[y]==true)
                        dfs5(y,0);
            }
        }
        //cout<<do_speca<<'\n';
        cout<<max(max(maks_global,maks_lulz)+do_speca+out,maks_xd);
    }
    return 0;
}