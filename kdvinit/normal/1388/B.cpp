/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n,m;
    cin>>n;

    m=(n+3)/4;
    n-=m;
    for(int i=1;i<=n;i++) cout<<9;
    for(int i=1;i<=m;i++) cout<<8;
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}