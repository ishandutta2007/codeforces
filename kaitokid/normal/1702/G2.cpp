#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int pr[200009][21],lvl[200009];
vector<int>ed[200009];
bool cmp(int x,int y)
{
    return lvl[x]<lvl[y];
}
void go(int x,int p,int l=0)
{
    pr[x][0]=p;
    lvl[x]=l;
    for(int i=0;i<ed[x].size();i++)
        if(ed[x][i]!=p)go(ed[x][i],x,l+1);

}
int lca(int x,int y)
{
    if(lvl[x]<lvl[y])swap(x,y);
    for(int i=19;i>=0;i--)
     if((lvl[x]-lvl[y])>=(1<<i))x=pr[x][i];
     if(x==y)return x;
     for(int i=19;i>=0;i--)
        if(pr[x][i]!=pr[y][i])x=pr[x][i],y=pr[y][i];
     return pr[x][0];
}
int anc(int x,int k)
{
    for(int i=0;i<20;i++)
        if(k&(1<<i))x=pr[x][i];
    return x;
}
bool isan(int x,int y)
{
    y=anc(y,lvl[y]-lvl[x]);
    return (x==y);

}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
for(int i=1;i<n;i++)
{
    int x,y;
    cin>>x>>y;
    ed[x].push_back(y);
    ed[y].push_back(x);
}
go(1,0);
for(int i=1;i<20;i++)
    for(int j=1;j<=n;j++)
    pr[j][i]=pr[pr[j][i-1]][i-1];
int q;
cin>>q;
while(q--)
{
    int z;
    vector<int>v;
    cin>>z;
    for(int i=0;i<z;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);

    }
    int u=v[0];
    for(int i=1;i<z;i++)u=lca(u,v[i]);
    vector<int>a,b;
    set<int>st;
    for(int i=0;i<z;i++)
    {
        if(v[i]==u)continue;
        st.insert(anc(v[i],lvl[v[i]]-lvl[u]-1));
    }
    if(st.size()>2){cout<<"NO"<<endl;continue;}
    int h=-1;
    if(!st.empty())h=(*st.begin());
    for(int i=0;i<z;i++)
    {
        if(v[i]==u)continue;
        if(anc(v[i],lvl[v[i]]-lvl[u]-1)==h)a.push_back(v[i]);
        else b.push_back(v[i]);
    }
    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end(),cmp);
    bool ans=true;
    for(int i=1;i<a.size();i++)
    if(!isan(a[i-1],a[i])){ans=false;break;};
    if(!ans){cout<<"NO"<<endl;continue;}
    for(int i=1;i<b.size();i++)
    if(!isan(b[i-1],b[i])){ans=false;break;};
    if(!ans){cout<<"NO"<<endl;continue;}
    cout<<"YES"<<endl;

}
return 0;
}