#include<bits/stdc++.h>
using namespace std;
int tab[30];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,licz=0;
    bool czy=false;
    cin>>a>>b>>c;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    for(int x=0;x<(a+1)/2;x++)
    {
        if(tab[x]+tab[a-x-1]==1)
            czy=true;
        if(tab[x]==2)
        {
            if(tab[a-x-1]==0)
                licz+=b;
            else if(tab[a-x-1]==1)
                licz+=c;
            else
            {
                licz+=2*min(b,c);
                if(x==a-x-1)
                    licz-=min(b,c);
            }

        }
        if(tab[x]==1)
            if(tab[a-x-1]==2)
                licz+=c;
         if(tab[x]==0)
            if(tab[a-x-1]==2)
                licz+=b;
    }
    if(czy==true)
        cout<<-1;
    else
        cout<<licz;
	return 0;
}