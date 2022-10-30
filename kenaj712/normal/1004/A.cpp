#include<bits/stdc++.h>
using namespace std;
long long tab[1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b;
    int licz=0;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    for(int x=0;x<a-1;x++)
    {
        if(tab[x+1]-tab[x]>=2*b)
            licz+=2;
        if(tab[x+1]-tab[x]==2*b)
            licz--;
    }
    cout<<licz+2;
	return 0;
}