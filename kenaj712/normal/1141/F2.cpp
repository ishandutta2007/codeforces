#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
vector<pair<int,pair<int,int>>> v;
vector<pair<int,int>> v2;
vector<pair<int,int>> v3;
vector<pair<int,int>> v4;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,maks=0,act,act2,koniec;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    for(int x=1;x<=a;x++)
    {
        act=0;
        for(int y=x;y<=a;y++)
        {
            act+=tab[y];
            v.push_back(make_pair(act,make_pair(y,x)));
        }
    }
    sort(v.begin(),v.end());
    v.push_back(make_pair(1e9+7,make_pair(1,1)));
    for(int x=0;x<v.size()-1;x++)
    {
        v2.push_back(v[x].second);
        if(v[x].first!=v[x+1].first)
        {
            koniec=-5;
            act=0;
            for(auto y:v2)
            {
                if(y.second>koniec)
                {
                    koniec=y.first;
                    act++;
                    v3.push_back(make_pair(y.second,y.first));
                }
            }
            v2.resize(0);
            if(act>maks)
            {
                maks=act;
                v4=v3;
            }
            v3.resize(0);
        }
    }
    cout<<v4.size()<<'\n';
    for(auto x:v4)
        cout<<x.first<<" "<<x.second<<'\n';
	return 0;
}