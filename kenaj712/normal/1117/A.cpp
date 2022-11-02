#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,licz,maks=-1,maks2=1,act=0;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        maks=max(maks,tab[x]);
    }
    for(int x=0;x<a;x++)
    {
        if(tab[x]==maks)
        {
            act++;
            maks2=max(act,maks2);
        }
        else
            act=0;
    }
    cout<<maks2;
	return 0;
}