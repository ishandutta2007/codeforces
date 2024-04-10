/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int x1,y1,z1,x2,y2,z2,x,y;
    cin>>x1>>y1>>z1>>x2>>y2>>z2;

    x=min(z1,y2);
    y=y1-x2-y2+x;
    if(y<0) y=0;

    cout<<2*x-2*y<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}