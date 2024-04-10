#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
bool czy[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    int maks_pom=0;
    for(int x=0;x<a;x++)
    {
        cin>>czy[x];
        if(czy[x]==true)
            maks_pom+=tab[x];
    }
    int tmp=0,maks;
    for(int x=0;x<b;x++)
        if(czy[x]==false)
            tmp+=tab[x];
    maks=tmp;
    for(int x=b;x<a;x++)
    {
        if(czy[x]==false)
            tmp+=tab[x];
        if(czy[x-b]==false)
            tmp-=tab[x-b];
        maks=max(maks,tmp);
    }
    cout<<maks+maks_pom;
	return 0;
}