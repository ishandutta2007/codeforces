#include<bits/stdc++.h>
using namespace std;
double tab[100005][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(15);
    int a;
    cin>>a;
    bool czy1=false,czy2=false;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x][0]>>tab[x][1];
        if(tab[x][1]>0)
            czy1=true;
        else
            czy2=true;
    }
    if(czy1==true&&czy2==true)
    {
        cout<<-1;
        return 0;
    }
    double pocz=-10000000,kon=10000000,prz1,prz2,maks1,maks2;
    int ile=100;
    while(ile--)
    {
        prz1=pocz+(kon-pocz)/3;
        prz2=prz1+(kon-pocz)/3;
        maks1=0;
        maks2=0;
        for(int x=0;x<a;x++)
        {
            maks1=max(maks1,abs((tab[x][0]-prz1)*(tab[x][0]-prz1)/(2*tab[x][1])+tab[x][1]/2));
            maks2=max(maks2,abs((tab[x][0]-prz2)*(tab[x][0]-prz2)/(2*tab[x][1])+tab[x][1]/2));
        }
        if(maks1<maks2)
            kon=prz2;
        else
            pocz=prz1;
    }
    maks1=0;
    for(int x=0;x<a;x++)
        maks1=max(maks1,abs((tab[x][0]-pocz)*(tab[x][0]-pocz)/(2*tab[x][1])+tab[x][1]/2));
    cout<<maks1;
	return 0;
}