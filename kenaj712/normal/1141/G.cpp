#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> pol[1000005];
vector<int> v;
bool odw[1000005];
int ktory[1000005];
int co;
void dfs(int a,int b)
{
    odw[a]=true;
    int licz=1;
    if(b==licz)
        licz++;
    for(auto x:pol[a])
    {
        if(odw[x.first]==false)
        {
            if(pol[a].size()>co)
            {
                ktory[x.second]=1;
                dfs(x.first,1);
            }
            else
            {
                if(b==licz)
                    licz++;
                ktory[x.second]=licz;
                dfs(x.first,licz);
                licz++;
            }
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b;
    for(int x=0;x<a-1;x++)
    {
        cin>>c>>d;
        pol[c].push_back(make_pair(d,x+1));
        pol[d].push_back(make_pair(c,x+1));
    }
    for(int x=1;x<=a;x++)
        v.push_back(-pol[x].size());
    sort(v.begin(),v.end());
    co=-v[b];
    cout<<co<<'\n';
    dfs(1,0);
    for(int x=1;x<=a-1;x++)
        cout<<ktory[x]<<" ";
	return 0;
}