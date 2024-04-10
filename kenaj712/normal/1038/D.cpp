#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    bool dod=false,uj=false;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        if(tab[x]>=0)
            dod=true;
        if(tab[x]<=0)
            uj=true;
    }
    long long licz=0;
    for(int x=0;x<a;x++)
        licz+=abs(tab[x]);
    if(a==1)
        cout<<tab[0];
    else if(a==2)
        cout<<max(tab[0]-tab[1],tab[1]-tab[0]);
    else
    {
        if(dod==true&&uj==true)
            cout<<licz;
        else if(dod==true)
        {
            long long mini=1e9+1;
            for(int x=0;x<a;x++)
                mini=min(mini,tab[x]);
            cout<<licz-2*mini;
        }
        else
        {
            long long mini=-1e9-1;
            for(int x=0;x<a;x++)
                mini=max(mini,tab[x]);
            cout<<licz+2*mini;
        }
    }
	return 0;
}