#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
bool odw[1000005];
int licz=0;
void dfs(int a)
{
    licz++;
    odw[a]=true;
    for(auto x:pol[a])
        if(odw[x]==false)
            dfs(x);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    int c,d;
    for(int x=0;x<b;x++)
    {
        cin>>c>>d;
        pol[c].push_back(d);
        pol[d].push_back(c);
    }
    int xd=0;
    for(int x=1;x<=a;x++)
        if(odw[x]==false)
        {
            dfs(x);
            xd+=licz-1;
            licz=0;
        }
    cout<<b-xd;
	return 0;
}