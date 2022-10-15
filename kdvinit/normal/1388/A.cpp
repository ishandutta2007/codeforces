/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    if(n<=30) { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;
    n-=30;
    if(n!=6 && n!=10 && n!=14) cout<<6<<" "<<10<<" "<<14<<" "<<n<<endl;
    else cout<<6<<" "<<10<<" "<<15<<" "<<n-1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}