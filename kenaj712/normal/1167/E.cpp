#include<bits/stdc++.h>
using namespace std;
int maks[1000005];
int pref_mini[1000005];
int mini[1000005];
int pref[1000005];
int suf[1000005];
int tab[1000005];
bool check(int a,int b,int x)
{
    if(b<a)
        return true;
    if(pref_mini[a-1]>=a&&pref[a-1]<=b&&suf[b+1]==0)
        return true;
    else
        return false;
}
set<int> s;
set<int>::iterator it;
int main()
{
	ios_base::sync_with_stdio(0);
	int a,b,maks1=0;
	cin>>a>>b;
	for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        s.insert(tab[x]);
        if(s.upper_bound(tab[x])!=s.end())
        {
            mini[tab[x]]=*s.upper_bound(tab[x]);
            it=s.end();
            it--;
            maks[tab[x]]=*it;
        }
    }
    for(int x=1;x<=b;x++)
        pref[x]=max(pref[x-1],maks[x]);
    for(int x=b;x>=1;x--)
        suf[x]=max(suf[x+1],maks[x]);
    pref_mini[0]=1e9;
    for(int x=1;x<=b;x++)
    {
        if(mini[x]!=0)
            pref_mini[x]=min(pref_mini[x-1],mini[x]);
        else
            pref_mini[x]=pref_mini[x-1];
    }
    long long licz=0;
    for(int x=1;x<=b;x++)
    {
        int pocz=x,kon=b,sr;
        while(pocz!=kon)
        {
            sr=(pocz+kon)/2;
            if(check(x,sr,b)==true)
                kon=sr;
            else
                pocz=sr+1;
        }
        if(check(x,pocz,b)!=false)
            licz+=b-pocz+1;
    }
    cout<<licz;

	return 0;
}