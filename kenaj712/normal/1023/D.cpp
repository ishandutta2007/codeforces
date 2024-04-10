#include<bits/stdc++.h>
using namespace std;
int tab[200005];
vector< pair<int,int> > v;
set<int> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        v.push_back(make_pair(-tab[x],x));
        s.insert(x);
    }
    sort(v.begin(),v.end());
    v.push_back(make_pair(1,1));
    if(-v[0].first!=b&&v[0].first!=0&&v[a-1].first!=0)
    {
        cout<<"NO";
        return 0;
    }
    if(v[0].first==0)
    {
        cout<<"YES"<<'\n';
        while(a--)
            cout<<b<<" ";

        return 0;
    }
    if(-v[0].first!=b)
    {
        for(int x=1;x<=a;x++)
        {
            if(tab[x]==0)
            {
                s.erase(x);
                tab[x]=b;
                break;
            }
        }
    }
    for(int x=0;x<a;x++)
    {
        int pocz=v[x].second,kon=v[x].second;
        if(v[x].first==0)
            break;
        while(v[x].first==v[x+1].first)
        {
            x++;
            kon=v[x].second;
        }
        if(s.upper_bound(pocz)!=s.end())
        while(*s.upper_bound(pocz)<kon)
        {
            int pom=*s.upper_bound(pocz);
            if(tab[pom]!=0&&tab[pom]!=-v[x].first)
            {
                //cout<<pom<<" ";
                cout<<"NO";
                return 0;
            }
            else
            {
                s.erase(pom);
                tab[pom]=-v[x].first;
            }
            if(s.upper_bound(pocz)==s.end())
                break;
        }
        s.erase(pocz);
        s.erase(kon);
    }
    cout<<"YES"<<'\n';
    for(int x=1;x<=a;x++)
        cout<<max(tab[x],1)<<" ";
	return 0;
}