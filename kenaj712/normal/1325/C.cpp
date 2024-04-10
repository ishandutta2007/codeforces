#include<bits/stdc++.h>
using namespace std;
int roz[1000005];
int co[1000005];
vector<pair<int,int>> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c;
    cin>>a;
    if(a==2)
    {
        cout<<0;
        return 0;
    }
    for(int x=0;x<a-1;x++)
    {
        cin>>b>>c;
        roz[b]++;
        roz[c]++;
        v.push_back(make_pair(b,c));
    }
    int licz=1;
    for(int x=0;x<a-1;x++)
        if(roz[v[x].first]==1 || roz[v[x].second]==1)
        {
            co[x]=licz;
            licz++;
        }
    for(int x=0;x<a-1;x++)
    {
        if(co[x]>0)
            cout<<co[x]-1<<'\n';
        else
        {
            cout<<licz-1<<'\n';
            licz++;
        }
    }
	return 0;
}