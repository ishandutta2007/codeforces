#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
set<int> possible;
int licz[1000005];
priority_queue<pair<int,int>> q;
int out[1000005];
vector<int> pos[1000005];
vector<int> v;
void czysc(int a)
{
    a+=2;
    for(int x=0;x<=a;x++)
        tab[x]=0;
    possible.clear();
    for(int x=0;x<=a;x++)
        licz[x]=0;
    while(!q.empty())
        q.pop();
    for(int x=0;x<=a;x++)
        out[x]=0;
    for(int x=0;x<=a;x++)
        pos[x].resize(0);
    v.resize(0);
}
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    for(int x=1;x<=a+1;x++)
        possible.insert(x);
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        possible.erase(tab[x]);
        licz[tab[x]]++;
        pos[tab[x]].push_back(x);
    }
    int filler=*possible.begin();
    for(int x=1;x<=a+1;x++)
        q.push(make_pair(licz[x],x));
    c-=b;
    while(b--)
    {
        pair<int,int> p=q.top();
        q.pop();
        int pom=pos[p.second].back();
        pos[p.second].pop_back();
        out[pom]=tab[pom];
        licz[p.second]--;
        p.first--;
        q.push(p);
    }
    while(!q.empty())
    {
        pair<int,int> p=q.top();
        q.pop();
        while(p.first--)
            v.push_back(p.second);
    }
    for(int x=0;x<v.size();x++)
    {
        if(c==0)
            break;
        if(v[x]!=v[(x+(v.size()+1)/2)%v.size()])
        {
            int pom=pos[v[x]].back();
            pos[v[x]].pop_back();
            out[pom]=v[(x+(v.size()+1)/2)%v.size()];
            c--;
        }
    }
    if(c==0)
        cout<<"YES"<<'\n';
    else
        cout<<"NO"<<'\n';
    if(!c)
    for(int x=1;x<=a;x++)
    {
        if(out[x])
            cout<<out[x]<<" ";
        else
            cout<<filler<<" ";
    }
    cout<<'\n';
    czysc(a);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}