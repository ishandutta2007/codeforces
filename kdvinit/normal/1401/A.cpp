/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int n,k;
    cin>>n>>k;

    if(k>n) { cout<<k-n<<endl; return; }
    if(n%2==k%2)  cout<<0<<endl;
    else cout<<1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}