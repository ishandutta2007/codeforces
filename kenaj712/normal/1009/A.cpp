#include<bits/stdc++.h>
using namespace std;
int tab[1005];
int tab2[1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    for(int x=0;x<b;x++)
        cin>>tab2[x];
    int licz=0;
    for(int x=0;x<a;x++)
    {
        if(tab[x]<=tab2[licz])
            licz++;
    }
    cout<<licz;
	return 0;
}