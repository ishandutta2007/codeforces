#include<bits/stdc++.h>
using namespace std;
int tab[30];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int b,c;
    cin>>b>>c;
    string a;
    cin>>a;
    for(int x=0;x<b;x++)
    {
        tab[int(a[x])-65]++;
    }
    int mini=1e6;
    for(int x=0;x<c;x++)
        mini=min(mini,tab[x]);
    cout<<c*mini;
	return 0;
}