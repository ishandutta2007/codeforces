#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int ile[1000005];
set<pair<pair<int,int>,int>> s;
set<pair<pair<int,int>,int>>::iterator it;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a;
    long long suma=0;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        suma+=tab[x];
    }
    int t;
    cin>>t;
    while(t--)
    {
        cin>>b>>c>>d;
        it=s.lower_bound(make_pair(make_pair(b,c),-1));
        if(it!=s.end() && (*it).first==make_pair(b,c))
        {
            ile[(*it).second]--;
            if(ile[(*it).second]<tab[(*it).second])
                suma++;
            s.erase(it);
        }
        if(d!=0)
        {
            s.insert(make_pair(make_pair(b,c),d));
            ile[d]++;
            if(ile[d]<=tab[d])
                suma--;
        }
        cout<<suma<<'\n';
    }
	return 0;
}