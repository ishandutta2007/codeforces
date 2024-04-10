#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
string d;
bool odw[1000005];
int licz[1000005];
int zlicz;
void dfs(int a)
{
    odw[a]=true;
    licz[d[a]-'a']++;
    zlicz++;
    for(auto x:pol[a])
        if(!odw[x])
            dfs(x);
}
void zeruj(int a)
{
    for(int x=0;x<a;x++)
    {
        pol[x].resize(0);
        odw[x]=false;
    }
}
void solve()
{
    int a,b;
    cin>>a>>b>>d;
    for(int x=0;x<a/2;x++)
    {
        pol[x].push_back(a-x-1);
        pol[a-x-1].push_back(x);
    }
    for(int x=0;x<a-b;x++)
    {
        pol[x].push_back(x+b);
        pol[x+b].push_back(x);
    }
    int lulz=0;
    for(int x=0;x<a;x++)
        if(!odw[x])
        {
            dfs(x);
            int maks=0;
            for(int z=0;z<26;z++)
            {
                maks=max(maks,licz[z]);
                licz[z]=0;
            }
            lulz+=(zlicz-maks);
            zlicz=0;
        }
    cout<<lulz<<'\n';
    zeruj(a);
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