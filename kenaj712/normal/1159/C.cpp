#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
long long tab2[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,maks=-1e18,mini=1e18;
    long long suma=0;
    bool czy=false;
    cin>>a>>b;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        maks=max(maks,tab[x]);
    }
    for(int x=0;x<b;x++)
    {
        cin>>tab2[x];
        mini=min(mini,tab2[x]);
    }
    if(maks>mini||(mini!=maks&&(b==1||a==1)))
    {
        cout<<-1;
        return 0;
    }
    for(int x=0;x<a;x++)
    {
        if(czy==true||tab[x]!=maks)
            suma+=tab[x]*b;
        else
        {
            czy=true;
            for(int y=0;y<b;y++)
                suma+=tab2[y];
        }
    }
    if(mini!=maks)
    {
        suma-=(mini-maks);
        sort(tab,tab+a);
        suma+=(mini-tab[a-2]);
    }


    cout<<suma;

	return 0;
}