#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> pol;
vector<int> lancuch;
vector<pair<int,int>> v;
bool ok[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>b;
        v.push_back(make_pair(b,x));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int pom=v[0].first;
    for(int x=0;x<=pom-1;x++)
        lancuch.push_back(v[x].second*2-1);
    lancuch.push_back(v[0].second*2);
    for(int x=0;x<lancuch.size()-1;x++)
        pol.push_back(make_pair(lancuch[x],lancuch[x+1]));
    for(int x=1;x<=pom-1;x++)
    {
         pol.push_back(make_pair(v[x].second*2,lancuch[x+v[x].first-1]));
         if(x+v[x].first-1==lancuch.size()-1)
            lancuch.push_back(v[x].second*2);
    }
    for(int x=pom;x<v.size();x++)
    {
         pol.push_back(make_pair(v[x].second*2-1,lancuch[0]));
         if(v[x].first!=1)
            pol.push_back(make_pair(v[x].second*2,lancuch[v[x].first-2]));
        else
            pol.push_back(make_pair(v[x].second*2,v[x].second*2-1));
    }
    for(auto x:pol)
        cout<<x.first<<" "<<x.second<<'\n';
	return 0;
}