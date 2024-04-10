#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    long long licz=0;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    sort(tab,tab+a+1);
    if(tab[a/2+1]==b)
        cout<<0;
    else if(tab[a/2+1]<b)
    {
        for(int x=a/2+1;x<=a;x++)
            licz+=max(b-tab[x],0);
        cout<<licz;
    }
    else
    {
        for(int x=a/2+1;x>=1;x--)
            licz+=max(tab[x]-b,0);
        cout<<licz;
    }
	return 0;
}