#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c,d;
    cin>>a;
    for(int x=1;x<a;x++)
    {
        cin>>c>>d;
        tab[c]++;
        tab[d]++;
    }
    for(int x=1;x<=a;x++)
        if(tab[x]==2)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
	return 0;
}