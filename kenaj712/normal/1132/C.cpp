#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
vector<pair<int,int>> v;
int pref[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b;
    for(int x=0;x<b;x++)
    {
        cin>>c>>d;
        for(int y=c;y<=d;y++)
            tab[y]++;
        v.push_back(make_pair(c,d));
    }
    int maks=0,act;
    for(int x=0;x<b;x++)
    {
        for(int y=v[x].first;y<=v[x].second;y++)
            tab[y]--;
        act=0;
        for(int z=1;z<=a;z++)
        {
            pref[z]=pref[z-1];
            if(tab[z]==1)
                pref[z]++;
            if(tab[z]>=1)
                act++;
        }
        for(int y=0;y<b;y++)
            if(y!=x)
                maks=max(maks,act-pref[v[y].second]+pref[v[y].first-1]);
        for(int y=v[x].first;y<=v[x].second;y++)
            tab[y]++;
    }
    cout<<maks;
	return 0;
}