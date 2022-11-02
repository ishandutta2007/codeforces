#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
vector<pair<int,int>> v2;
vector<pair<int,int>> v3;
int suf[4000005];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
    {
        int c,d;
        cin>>c>>d;
        v.push_back(make_pair(c,d));
    }
    for(int x=0;x<b;x++)
    {
        int c,d;
        cin>>c>>d;
        v2.push_back(make_pair(c,d));
    }
    for(auto x:v2)
    {
        int maks1=0,maks2=0;
        for(auto y:v)
        {
            maks1=max(0,x.first+1-y.first);
            maks2=max(0,x.second+1-y.second);
            v3.push_back(make_pair(maks1,maks2));
        }
    }
    int mini=1e9+7;
    v3.push_back(make_pair(0,0));
    sort(v3.begin(),v3.end());
   // for(auto x:v3)
    //    cout<<x.first<<" "<<x.second<<'\n';
    for(int x=v3.size()-1;x>=0;x--)
        suf[x]=max(suf[x+1],v3[x].second);
    for(int x=0;x<v3.size();x++)
        mini=min(mini,suf[x+1]+v3[x].first);
    cout<<mini;
	return 0;
}