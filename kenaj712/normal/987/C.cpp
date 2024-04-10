#include<bits/stdc++.h>
using namespace std;
int tab1[3005];
int tab2[3005];
int prawo[3005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab1[x];
    for(int x=0;x<a;x++)
        cin>>tab2[x];
    for(int x=0;x<a;x++)
    {
        prawo[x]=1e9;
        for(int y=x+1;y<a;y++)
        {
            if(tab1[y]>tab1[x])
                prawo[x]=min(prawo[x],tab2[y]);
        }
    }
    //for(int x=0;x<a;x++)
       // cout<<prawo[x]<<" ";
    int mini=1e9;
    for(int x=0;x<a;x++)
    {
        for(int y=x+1;y<a;y++)
        {
            if(prawo[y]!=1e9&&tab1[x]<tab1[y])
                mini=min(mini,tab2[x]+tab2[y]+prawo[y]);
        }
    }
    if(mini!=1e9)
        cout<<mini;
    else
        cout<<-1;
	return 0;
}