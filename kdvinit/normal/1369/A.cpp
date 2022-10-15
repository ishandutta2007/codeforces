/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int n;
    cin>>n;
    
    if(n%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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