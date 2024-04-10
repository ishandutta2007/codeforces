#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,maks=0;
    cin>>a;
    int b;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        cout<<b+maks<<" ";
        maks=max(maks,b+maks);
    }
	return 0;
}