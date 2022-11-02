#include<bits/stdc++.h>
using namespace std;


vector<int> pol[1000005];
int tab[1000005];
vector<int> v;

void dfs(int a,int b)
{
    for(auto x:pol[a])
        if(x != b)
            dfs(x,a);
    if(a != 1)
    {
        int licz = 0;
        for(auto x:pol[a])
            if(x != b)
                if(tab[x] == 0)
                    licz++;
        if(licz > 0)
        {
            v.push_back(licz);
            tab[a] = 1;
            for(auto x:pol[a])
                if(x != b && tab[x] == 0)
                    tab[x] = 2;
        }
    }
}
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a-1;x++)
    {
        int c,d;
        cin>>c>>d;
        pol[c].push_back(d);
        pol[d].push_back(c);
    }
    dfs(1,0);
    int licz = 0;
    for(int x=2;x<=a;x++)
        if(tab[x] == 0)
            licz++;
    int sum = 0;
    for(auto x:v)
        sum += x;
    if(v.empty())
        cout<<licz<<'\n';
    else
        cout<<sum - v.size() + 1 + max(0, licz - 1)<<'\n';
    v.resize(0);
    for(int x=0;x<=a;x++)
    {
        pol[x].resize(0);
        tab[x] = 0;
    }
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