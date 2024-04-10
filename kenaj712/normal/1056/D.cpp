#include<bits/stdc++.h>
using namespace std;
vector<int> polaczenia[1000005];
bool odw[1000005];
int xd[1000005];
int wtf[1000005];
void dfs(int a)
{
    int pom=0;
    odw[a]=true;
    for(int x=0;x<polaczenia[a].size();x++)
        if(odw[polaczenia[a][x]]==false)
        {
            dfs(polaczenia[a][x]);
            pom+=xd[polaczenia[a][x]];
        }

    if(polaczenia[a].size()==1&&a!=1)
        pom++;
    xd[a]=pom;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c;
    cin>>a;
    if(a==1)
    {
        cout<<1;
        return 0;
    }
    for(int x=2;x<=a;x++)
    {
        cin>>c;
        polaczenia[x].push_back(c);
        polaczenia[c].push_back(x);
    }
    dfs(1);
    for(int x=1;x<=a;x++)
        wtf[xd[x]]++;
    int licz=wtf[1],gdzie=1;
    for(int x=1;x<=a;x++)
    {
        while(licz<x)
        {
            gdzie++;
            licz+=wtf[gdzie];
        }
        cout<<gdzie<<" ";
    }

    return 0;
}