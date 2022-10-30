#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c;
    cin>>a>>b;
    for(int x=0;x<b;x++)
    {
        cin>>c;
        tab[c]++;
    }
    int mini=10e9;
    for(int x=1;x<=a;x++)
        mini=min(mini,tab[x]);
    cout<<mini;

	return 0;
}