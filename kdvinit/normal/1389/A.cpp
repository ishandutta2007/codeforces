/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int l,r;
    cin>>l>>r;

    if(r<2*l) cout<<-1<<" "<<-1<<endl;
    else cout<<l<<" "<<2*l<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}