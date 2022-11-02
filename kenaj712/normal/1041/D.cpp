#include<bits/stdc++.h>
using namespace std;
int tab[200005][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x][0]>>tab[x][1];
    long long kon=0,maks=0,odl=0;
    for(int pocz=0;pocz<a;pocz++)
    {
        while(kon+1<a)
        {
            if(odl+tab[kon+1][0]-tab[kon][1]<b)
            {
                odl+=tab[kon+1][0]-tab[kon][1];
                kon++;
            }
            else
                break;
        }
        maks=max(maks,tab[kon][1]-tab[pocz][0]+b-odl);
        if(pocz!=a-1)
            odl-=tab[pocz+1][0]-tab[pocz][1];
    }
    cout<<maks;
	return 0;
}