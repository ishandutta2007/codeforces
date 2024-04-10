#include<bits/stdc++.h>
using namespace std;
int tab[300005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b=0,c=0,maks=0;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    sort(tab,tab+a);
    for(int x=0;x<a;x++)
    {
        if(b==tab[x])
            c++;
        else
        {
            c=1;
            b=tab[x];
        }
        maks=max(maks,c);
    }
    cout<<a-maks;
	return 0;
}