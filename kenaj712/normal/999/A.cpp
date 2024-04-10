#include<bits/stdc++.h>
using namespace std;
int tab[505];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    int pocz=a+1,kon=0;
    for(int x=1;x<=a;x++)
    {
        if(tab[x]>b)
        {
            pocz=x;
            break;
        }
    }
    for(int x=a;x>=1;x--)
        if(tab[x]>b)
    {
        kon=x;
        break;
    }
    if(pocz==a+1)
        cout<<a;
    else
        cout<<pocz-1+a-kon;
	return 0;
}