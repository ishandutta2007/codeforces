/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int a,b,n,m;
    cin>>a>>b>>n>>m;

    if(m>min(a,b)) { cout<<"No"<<endl; return; }
    if(n>a+b-m) { cout<<"No"<<endl; return; }

    cout<<"Yes"<<endl;
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