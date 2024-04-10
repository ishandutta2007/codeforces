#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> lewo;
set<pair<int,int>> prawo;
vector<int> v;
void solve()
{
    int a;
    cin>>a;
    a*=2;
    int licz=0,c;
    for(int x=1;x<=a/2;x++)
    {
        cin>>c;
        if(c==1)
            licz++;
        else
            licz--;
        lewo.insert(make_pair(licz,a/2-x));
    }
    for(int x=1;x<=a/2;x++)
    {
        cin>>c;
        v.push_back(c);
    }
    reverse(v.begin(),v.end());
    licz=0;
    for(int x=1;x<=a/2;x++)
    {
        c=v[x-1];
        if(c==1)
            licz++;
        else
            licz--;
        prawo.insert(make_pair(licz,a/2-x));
    }
    lewo.insert(make_pair(0,a/2));
    prawo.insert(make_pair(0,a/2));
    int maks=1e6;
    for(auto x:lewo)
    {
        set<pair<int,int>>::iterator it=prawo.lower_bound(make_pair(-x.first,0));
        if(it!=prawo.end() && (*it).first==-x.first)
            maks=min(maks,x.second+(*it).second);
    }
    cout<<maks<<'\n';
    lewo.clear();
    prawo.clear();
    v.resize(0);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}