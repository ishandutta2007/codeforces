#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin>>a>>b;
	for(int x=0;x<a;x++)
        cin>>tab[x];
    sort(tab,tab+a);
    int maks=0;
    for(int x=0;x<a;x++)
        for(int y=x;y<a;y++)
        {
            if(tab[y]-tab[x]<=b)
                maks=max(maks,y-x+1);
        }
    cout<<a-maks;
	return 0;
}