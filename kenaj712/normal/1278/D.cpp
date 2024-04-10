#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
vector<int> pol[1000005];
set<pair<pair<int,int>,int>> s;
set<pair<pair<int,int>,int>>::iterator it;
bool odw[1000005];
void dfs(int a)
{
    odw[a]=true;
    for(auto x:pol[a])
        if(odw[x]==false)
            dfs(x);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c,d;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>c>>d;
        v.push_back(make_pair(c,d));
    }
    sort(v.begin(),v.end());
    s.insert(make_pair(make_pair(-1,-1),-1));
    int pom=0;
    for(int x=0;x<a;x++)
    {
        it=s.lower_bound(make_pair(make_pair(v[x].second,0),0));
        it--;
        while(pom<a&&v[x].first<(*it).first.first)
        {
            pom++;
            pol[x].push_back((*it).second);
            pol[(*it).second].push_back(x);
            it--;
        }
        s.insert(make_pair(make_pair(v[x].second,v[x].first),x));
    }
    if(pom!=a-1)
    {
        cout<<"NO";
        return 0;
    }
    dfs(0);
    for(int x=0;x<a;x++)
        if(odw[x]==false)
        {
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
	return 0;
}