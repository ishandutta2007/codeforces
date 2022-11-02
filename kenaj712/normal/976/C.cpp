#include<bits/stdc++.h>
using namespace std;
vector <pair<int,pair<int,int> > > v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>b>>c;
        v.push_back(make_pair(b,make_pair(c,x)));
    }
    sort(v.begin(),v.end());
    v.push_back(make_pair(-1,make_pair(-1,-1)));
    int maks=-1,indeks=-1;
    for(int x=0;x<a;x++)
    {
        if(v[x+1].first==v[x].first)
        {
            cout<<v[x].second.second<<" "<<v[x+1].second.second;
            return 0;
        }
        if(maks>=v[x].second.first)
        {
            cout<<v[x].second.second<<" "<<indeks;
            return 0;
        }
        maks=v[x].second.first;
        indeks=v[x].second.second;
    }
    cout<<-1<<" "<<-1;
    return 0;
}