#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
bool odw[1000005];
int pre[1000005];
int post[1000005];
int parent[1000005];
int depth[1000005];
vector<int> v;
int licz_pre,licz_post;
void dfs(int a,int b)
{
    parent[a]=b;
    odw[a]=true;
    pre[a]=licz_pre;
    depth[a]=depth[b]+1;
    licz_pre++;
    for(auto x:pol[a])
        if(!odw[x])
            dfs(x,a);
    post[a]=licz_post;
    licz_post++;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    int c,d;
    for(int x=0;x<a-1;x++)
    {
        cin>>c>>d;
        pol[c].push_back(d);
        pol[d].push_back(c);
    }
    dfs(1,1);
    while(b--)
    {
        cin>>c;
        int maks=0;
        while(c--)
        {
            cin>>d;
            v.push_back(d);
            if(depth[d]>depth[maks])
                maks=d;
        }
        int xd=0;
        for(auto x:v)
        {
            d=parent[x];
            if(pre[d]<=pre[maks] && post[d]>=post[maks])
                xd++;
        }
        if(xd==v.size())
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
        v.resize(0);
    }
	return 0;
}