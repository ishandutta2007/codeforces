#include<bits/stdc++.h>
using namespace std;
int pot=(1<<20);
int drzewo[4000005];
void ins(int a)
{
    int pom=a+pot;
    while(pom!=0)
    {
        drzewo[pom]++;
        pom/=2;
    }
}
int check(int a,int b)
{
    int l=a+pot,r=b+pot,war;
    war=drzewo[l];
    if(l!=r)
        war+=drzewo[r];
    while(l/2!=r/2)
    {
        if(l%2==0)
            war+=drzewo[l+1];
        if(r%2==1)
            war+=drzewo[r-1];
        l/=2;
        r/=2;
    }
    return war;
}
int tab[1000005];
vector<pair<int,int>> v;
vector<pair<long long,pair<int,int>>> q;
vector<pair<int,int>> ans;
int query(int n,int b)
{
    int pocz=1,kon=b,sr;
    while(pocz!=kon)
    {
        sr=(pocz+kon)/2;
        if(check(1,sr)>=n)
            kon=sr;
        else
            pocz=sr+1;
    }
    return pocz;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,t,c;
    long long e;
    cin>>a>>b>>t;
    for(int x=0;x<a;x++)
    {
        cin>>c;
        tab[c]++;
    }
    for(int x=0;x<t;x++)
    {
        cin>>e;
        e-=a;
        q.push_back(make_pair(e,make_pair(0,x)));
    }
    for(int x=1;x<=b;x++)
        v.push_back(make_pair(tab[x],x));
    sort(v.begin(),v.end());
    long long now=0,last=-1;
    for(int x=0;x<b;x++)
    {
        now+=x*(v[x].first-last);
        last=v[x].first;
        q.push_back(make_pair(now,make_pair(1,v[x].second)));
    }
    sort(q.begin(),q.end());
    now=0,last=0;
    long long licz=0,pom;
    for(auto x:q)
    {
        if(x.second.first==0)
        {
            pom=(x.first-last-1)%licz+1;
            ans.push_back(make_pair(x.second.second,query(pom,b)));
        }
        else
        {
            last=x.first;
            licz++;
            ins(x.second.second);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans)
        cout<<x.second<<'\n';
	return 0;
}