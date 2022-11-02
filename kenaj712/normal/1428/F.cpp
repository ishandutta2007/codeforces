#include<bits/stdc++.h>
using namespace std;
#define int long long
int a;
int tab[1000005];
long long calc(int l,int r)
{
    //cout<<l<<" "<<r<<'\n';
    bool czy[2]={0,0};
    for(int x=l;x<=r;x++)
        czy[tab[x]]=true;
    if(!(czy[0]&czy[1]))
    {
        if(czy[0])
            return 0;
        else
        {
            long long ret=0;
            for(int x=1;x<=(r-l+1);x++)
                ret+=x*(r-l+1-x+1);
            return ret;
        }
    }
    int div;
    int pocz=l,kon=r;
    while(pocz<kon)
    {
        if(pocz<r && (tab[pocz]!=1 || tab[pocz+1]!=1))
            div=pocz;
        if(kon>l && (tab[kon]!=1 || tab[kon-1]!=1))
            div=kon-1;
        pocz++;
        kon--;
    }
    long long ret=calc(l,div) + calc(div+1,r);
    vector<int> v1,v2;
    int act=0;
    for(int x=div;x>=l;x--)
    {
        if(tab[x]==0)
            act=0;
        else
            act++;
        v1.push_back(act);
        if(v1.size()>1)
            v1[v1.size()-1] = max(v1.back() , v1[v1.size()-2]);
    }
    act=0;
    for(int x=div+1;x<=r;x++)
    {
        if(tab[x]==0)
            act=0;
        else
            act++;
        v2.push_back(act);
        if(v2.size()>1)
            v2[v2.size()-1] = max(v2.back() , v2[v2.size()-2]);
    }
    long long sum=0;
    for(auto x:v2)
        sum+=x;
    int where=0;
    for(auto x:v1)
    {
        while(where!=v2.size() && x>=v2[where])
        {
            sum-=v2[where];
            where++;
        }
        ret+=sum + x*where;
    }
    return ret;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>a;
	string d;
	cin>>d;
	for(int x=0;x<a;x++)
        tab[x+1]=d[x]-'0';
    cout<<calc(1,a);
	return 0;
}