/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int a,b,c;
    cin>>a>>b>>c;

    if(a<c) cout<<1<<" ";
    else cout<<-1<<" ";

    if(a*b>c) cout<<b<<endl;
    else cout<<-1<<endl;
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