#include<bits/stdc++.h>
using namespace std;
int tab[1000005][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,licz=0;
    cin>>a>>b>>c;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x][0]>>tab[x][1];
        if(x!=0)
            licz+=(tab[x][0]-tab[x-1][0]-tab[x-1][1])/c;
    }
    licz+=(b-tab[a-1][0]-tab[a-1][1])/c;
    licz+=tab[0][0]/c;
    cout<<licz;

	return 0;
}