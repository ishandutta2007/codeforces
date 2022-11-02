#include<bits/stdc++.h>
using namespace std;
int waga[1000005];
int tab[1000005];
vector<int> pol[1000005];
bool odw[1000005];
int mini[1000005];
int maks[1000005];
vector<pair<pair<int,int>,int>> v;
vector<int> v2;
void dfs(int a)
{
    odw[a]=true;
    for(auto x:pol[a])
        if(odw[x]==false)
            dfs(x);
    v2.push_back(waga[a]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        waga[tab[x]]++;
        if(mini[tab[x]]==0)
            mini[tab[x]]=x;
        maks[tab[x]]=x;
    }
    for(int x=1;x<=200000;x++)
        if(mini[x]!=0)
            v.push_back(make_pair(make_pair(mini[x],maks[x]),x));
    sort(v.begin(),v.end());
    int maksi=0,ziomek=0;
    for(auto x:v)
    {
        if(x.first.first<maksi)
        {
            pol[ziomek].push_back(x.second);
            pol[x.second].push_back(ziomek);
        }
        if(x.first.second>maksi)
        {
            maksi=x.first.second;
            ziomek=x.second;
        }
    }
    long long out=0;
    for(int x=1;x<=a;x++)
        if(odw[x]==false)
        {
            dfs(x);
            sort(v2.begin(),v2.end());
            long long suma=0;
            for(auto x:v2)
                suma+=x;
            out+=suma-v2.back();
            v2.resize(0);
        }
    cout<<out;
	return 0;
}