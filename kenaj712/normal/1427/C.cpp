#include<bits/stdc++.h>
using namespace std;
int pref[1000005];
int tab[1000005][2];
int t[1000005];
int out[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>b>>a;
    t[0]=0;
    tab[0][0]=1;
    tab[0][1]=1;
    int koniec=0;
    for(int x=1;x<=a;x++)
    {
        cin>>t[x]>>tab[x][0]>>tab[x][1];
        int maks=-1;
        for(int y=x-1;y>=max(0,x-1004);y--)
            if(t[x]-t[y]>=abs(tab[x][0]-tab[y][0]) + abs(tab[x][1] - tab[y][1]))
                maks=max(maks,out[y]);
        if(x>=1005)
            maks=max(maks,pref[x-1005]);
        out[x]=maks+1;
        if(maks==-1)
            out[x]=-1e6;
        pref[x]=max(pref[x-1],out[x]);
        koniec=max(koniec,out[x]);

    }
    cout<<koniec;
	return 0;
}