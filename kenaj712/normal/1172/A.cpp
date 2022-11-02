#include<bits/stdc++.h>
using namespace std;
int tab1[1000005];
int tab2[1000005];
set<int> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>tab1[x];
        if(tab1[x]!=0)
            s.insert(tab1[x]);
    }
    int maks=0,where=-1;
    for(int x=1;x<=a;x++)
    {
        cin>>tab2[x];
        if(tab2[x]!=0)
            maks=max(maks,x-tab2[x]+1);
        if(tab2[x]==1)
            where=x;
    }
    bool czy=false;
    if(where==-1)
        czy=true;
    if(where!=-1)
    for(int x=where;x<=a;x++)
    {
        if(tab2[x]!=x-where+1)
        {
            czy=true;
            break;
        }
    }
    if(czy==false)
    {
        int pom=tab2[a];
        bool xd=false;
        for(int x=1;x<where;x++)
        {
            if(tab2[x]==0)
                continue;
            if(tab2[x]-pom-1<x)
            {
                xd=true;
            }
        }
        if(xd==false)
        {
            cout<<a-pom;
            return 0;
        }
    }
    cout<<maks+a;
	return 0;
}