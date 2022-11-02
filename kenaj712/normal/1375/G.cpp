#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
bool odw[1000005];
int licz[2];
void dfs(int a,int b)
{
    odw[a]=true;
    licz[b]++;
    for(auto x:pol[a])
        if(!odw[x])
        {
            dfs(x,b^1);
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
    cout<<min(licz[0],licz[1])-1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--)
        solve();
	return 0;
}