#include<bits/stdc++.h>
using namespace std;
long long v[3000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin>>a;
	for(int x=0;x<a;x++)
    {
        int b;
        cin>>b;
        v[x-b+1000000]+=b;
    }
    long long maks=0;
    for(int x=0;x<3e6;x++)
        maks=max(maks,v[x]);
    cout<<maks;
	return 0;
}