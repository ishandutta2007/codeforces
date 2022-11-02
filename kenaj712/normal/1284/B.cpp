#include<bits/stdc++.h>
using namespace std;
int pref[1000005];
int tab[1000005];
vector<int> v;
long long zlicz=0;
long long out=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c,d;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>c;
        int maks=-1e9,mini=1e9;
        bool czy=false;
        for(int y=0;y<c;y++)
        {
            cin>>d;
            d++;
            if(d>mini)
                czy=true;
            mini=min(mini,d);
            maks=max(maks,d);
        }
        if(czy==true)
            zlicz++;
        else
        {
            v.push_back(maks);
            tab[mini]++;
        }
    }
    for(int x=1;x<=1e6+3;x++)
        pref[x]=pref[x-1]+tab[x];
    for(auto x:v)
        out+=pref[x-1];
    cout<<out+zlicz*zlicz+zlicz*v.size()*2;
    return 0;
}