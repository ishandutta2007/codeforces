#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,maks=-(1e9+1),mini=1e9+1;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        maks=max(b,maks);
        mini=min(mini,b);
    }
    cout<<maks-mini+1-a;
	return 0;
}