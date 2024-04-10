#include<bits/stdc++.h>
using namespace std;
int cost[200005];
int tab[200005];
bool odw[200005];
bool cykl[200005];
vector <int> v;
int suma=0;
void dfs(int a)
{
    v.push_back(a);
    odw[a]=true;
    if(odw[tab[a]]==false)
        dfs(tab[a]);
    else
    {
        if(cykl[tab[a]]==true)
        {
            while(v.empty()==false)
            {
                cykl[v[v.size()-1]]=true;
                v.pop_back();
            }
        }
        else
        {
            //cout<<a<<'\n';
            int mini=100000;
            while(v[v.size()-1]!=tab[a])
            {
                mini=min(mini,cost[v[v.size()-1]]);
                cykl[v[v.size()-1]]=true;
                v.pop_back();
            }
            mini=min(mini,cost[v[v.size()-1]]);
            cykl[v[v.size()-1]]=true;
            v.pop_back();
            suma+=mini;
            while(v.empty()==false)
            {
                cykl[v[v.size()-1]]=true;
                v.pop_back();
            }
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>cost[x];
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    for(int x=1;x<=a;x++)
    {
        if(odw[x]==false)
            dfs(x);
    }
    cout<<suma;
	return 0;
}