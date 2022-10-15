/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int a[3];
    cin>>a[0]>>a[1]>>a[2];

    sort(a,a+3);
    if(a[1]!=a[2]) { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;
    cout<<a[0]<<" "<<a[0]<<" "<<a[2]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
        solve();
	}
	return 0;
}