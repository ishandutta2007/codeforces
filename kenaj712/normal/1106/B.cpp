#include<bits/stdc++.h>
using namespace std;
set<pair<pair<long long,int>,long long>> s;
long long ile[1000005];
long long cost[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,t;
	cin>>a>>t;
	for(int x=1;x<=a;x++)
        cin>>ile[x];
    for(int x=1;x<=a;x++)
    {
        cin>>cost[x];
        s.insert(make_pair(make_pair(cost[x],x),ile[x]));
    }
    long long c,d,licz,e,pom1,pom2,pom3;
    bool wtf=false;
    while(t--)
    {
        cin>>c>>d;
        if(wtf==true)
        {
            cout<<0<<'\n';
            continue;
        }
        pom1=cost[c],pom2=ile[c];
        licz=0;
        e=d;
        licz+=cost[c]*min(d,ile[c]);
        d-=min(d,ile[c]);
        ile[c]-=min(e,ile[c]);
        s.erase(make_pair(make_pair(pom1,c),pom2));
        if(ile[c]!=0)
            s.insert(make_pair(make_pair(cost[c],c),ile[c]));
        while(d>0)
        {
            if(s.empty()==true)
            {
                wtf=true;
                break;
            }
            c=(*s.begin()).first.second;
            s.erase(s.begin());
            e=d;
            licz+=cost[c]*min(d,ile[c]);
            d-=min(d,ile[c]);
            ile[c]-=min(e,ile[c]);
            if(ile[c]!=0)
                s.insert(make_pair(make_pair(cost[c],c),ile[c]));
        }
        if(wtf==true)
        {
            cout<<0<<'\n';
            continue;
        }
        cout<<licz<<'\n';
    }
	return 0;
}