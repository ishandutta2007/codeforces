/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int a,b;
    cin>>a>>b;

    if(a*b==0) cout<<0<<endl;
    else if(max(a,b)>=2*min(a,b)) cout<<min(a,b)<<endl;
    else cout<<(a+b)/3<<endl;

    return;
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