#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
bool odw[1000005];
bool ziomek[1000005];
void dfs(int a)
{
    if(ziomek[a])
    {
        vector<int> v;
        for(auto x:pol[a])
            if(!odw[x])
            {
                v.push_back(x);
                odw[x] = true;
            }
        for(auto x:v)
            dfs(x);
    }
    else
    {
        for(auto x:pol[a])
            if(!odw[x])
            {
                odw[x] = true;
                ziomek[x] = true;
                dfs(x);
            }
    }
}
void solve()
{
    int a,b;
    cin>>a>>b;
    while(b--)
    {
        int c,d;
        cin>>c>>d;
        pol[c].push_back(d);
        pol[d].push_back(c);
    }
    odw[1] = true;
    ziomek[1] = true;
    dfs(1);
    vector<int> v;
    bool czy = true;
    for(int x=1;x<=a;x++)
    {
        if(!odw[x])
            czy = false;
        if(ziomek[x])
            v.push_back(x);
        pol[x].resize(0);
        odw[x] = false;
        ziomek[x] = false;
    }
    if(czy)
    {
        cout<<"YES\n"<<v.size()<<'\n';
        for(auto x:v)
            cout<<x<<" ";
        cout<<'\n';
    }
    else
        cout<<"No\n";
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