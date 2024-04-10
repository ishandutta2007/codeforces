#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> pol[5005];
bool odw[5005];
bool tmp[5005];
int kolor[5005];
void dfs(int a)
{
    odw[a]=true;
    tmp[a]=true;
    for(auto x:pol[a])
    {
        if(odw[x.first]==false)
        {
            dfs(x.first);
            kolor[x.second]=1;
        }
        else if(tmp[x.first]==false)
            kolor[x.second]=1;
        else
            kolor[x.second]=2;

    }
    tmp[a]=false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b;
    for(int x=0;x<b;x++)
    {
        cin>>c>>d;
        pol[c].push_back(make_pair(d,x));
    }
    for(int x=1;x<=a;x++)
        if(odw[x]==false)
            dfs(x);
    int maks=1;
    for(int x=0;x<b;x++)
        maks=max(maks,kolor[x]);
    cout<<maks<<'\n';
    for(int x=0;x<b;x++)
        cout<<kolor[x]<<" ";
	return 0;
}