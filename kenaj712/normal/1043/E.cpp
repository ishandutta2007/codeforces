#include<bits/stdc++.h>
using namespace std;
long long a[300005];
long long b[300005];
long long out[300005];
vector< pair<long long,pair<long long,long long> > > v;
long long pref_x[300005];
long long pref_y[300005];
long long suma_y;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long ile,t;
    cin>>ile>>t;
    for(int x=0;x<ile;x++)
    {
        cin>>a[x]>>b[x];
        v.push_back(make_pair(a[x]-b[x],make_pair(a[x],b[x])));
        out[x]=a[x]*(ile-1);
        suma_y+=b[x];
    }
    sort(v.begin(),v.end());
    pref_x[0]=v[0].second.first;
    pref_y[0]=v[0].second.second;
    for(int x=1;x<ile;x++)
    {
        pref_x[x]=v[x].second.first+pref_x[x-1];
        pref_y[x]=v[x].second.second+pref_y[x-1];
    }
    for(int x=0;x<ile;x++)
    {
        out[x]+=suma_y-b[x];
        int pocz=0,kon=ile-1,sr;
        long long pom=a[x]-b[x];
        while(kon-pocz>1)
        {
            sr=(pocz+kon)/2;
            if(v[sr].first>pom)
                kon=sr-1;
            else
                pocz=sr;
        }
        if(kon-pocz==1&&v[kon].first<pom)
            pocz++;
        out[x]+=pref_x[pocz];
        out[x]-=pref_y[pocz];
        out[x]+=b[x]*(pocz+1);
        out[x]-=a[x]*(pocz+1);
    }
    int c,d;
    while(t--)
    {
        cin>>c>>d;
        c--;
        d--;
        out[c]-=min(a[c]+b[d],a[d]+b[c]);
        out[d]-=min(a[c]+b[d],a[d]+b[c]);
    }
    for(int x=0;x<ile;x++)
        cout<<out[x]<<" ";
	return 0;
}