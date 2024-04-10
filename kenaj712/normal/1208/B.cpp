#include<bits/stdc++.h>
using namespace std;
set<int> s;
int tab[2005];
vector<int> v;
int zlicz[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        s.insert(tab[x]);
    }
    for(auto x:s)
        v.push_back(x);
    int mini=1e9,licz=0;
    for(int x=1;x<=a;x++)
    {
        tab[x]=lower_bound(v.begin(),v.end(),tab[x])-v.begin();
        zlicz[tab[x]]++;
        if(zlicz[tab[x]]==2)
            licz++;
    }
    if(licz==0)
        mini=0;
    for(int x=1;x<=a;x++)
    {
        for(int y=x;y<=a;y++)
        {
            zlicz[tab[y]]--;
            if(zlicz[tab[y]]==1)
                licz--;
            if(licz==0)
                mini=min(mini,y-x+1);
        }
        for(int y=x;y<=a;y++)
        {
            zlicz[tab[y]]++;
            if(zlicz[tab[y]]==2)
                licz++;
        }
    }
    cout<<mini;



	return 0;
}