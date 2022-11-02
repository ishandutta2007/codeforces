#include<bits/stdc++.h>
using namespace std;
vector<int> v[105];
vector<pair<int,int>> v2[105];
bool odw[105];
pair<int,int> ans[105];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a*b;x++)
    {
        int c;
        cin>>c;
        v[c].push_back(x);
        v2[v[c].size()].push_back(make_pair(x,c));
    }
    int pom = a/(b-1);
    if(a%(b-1))
        pom++;
    for(int x=2;x<=b+1;x++)
    {
        sort(v2[x].begin(),v2[x].end());
        int siemako = pom;
        for(auto y:v2[x])
        {
            if(odw[y.second])
                continue;
            if(siemako == 0)
                continue;
            siemako--;
            odw[y.second] = true;
            ans[y.second] = make_pair(v[y.second][x-2],v[y.second][x-1]);
        }
    }
    for(int x=1;x<=a;x++)
        cout<<ans[x].first<<" "<<ans[x].second<<'\n';
	return 0;
}