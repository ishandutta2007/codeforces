/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int x,y,n;
    cin>>x>>y>>n;
    n-=y;
    n/=x;
    n*=x;
    n+=y;
    cout<<n<<endl;
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