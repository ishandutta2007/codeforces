#include<bits/stdc++.h>
using namespace std;
long long q[1000005];
long long tab[1000005];
vector<pair<long long,long long>> v;
set<pair<long long,long long>> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,c,d;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    int t;
    cin>>t;
    for(int x=0;x<t;x++)
    {
        cin>>c>>d;
        q[x]=d-c;
        v.push_back(make_pair(d-c,-2));
    }
    long long pom=a;
    sort(tab,tab+a);
    tab[a]=3e18;
    for(int x=0;x<a;x++)
    {
        if(tab[x+1]==tab[x])
            pom--;
        else
            v.push_back(make_pair(tab[x+1]-tab[x]-1,-1));
    }
    long long last=0,act=pom;
    sort(v.begin(),v.end());
    for(int x=0;x<v.size();x++)
    {
        if(v[x].first!=last)
        {
            act+=pom*(v[x].first-last);
            last=v[x].first;
        }
        if(v[x].second==-2)
            s.insert(make_pair(v[x].first,act));
        else
            pom--;
    }
    for(int x=0;x<t;x++)
        cout<<(*s.lower_bound(make_pair(q[x],-1))).second<<" ";
	return 0;
}