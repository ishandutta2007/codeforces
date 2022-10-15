/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n,k,l;
    cin>>n>>k>>l;

    int d[n+1],pos=-k;
    for(int i=1;i<=n;i++) cin>>d[i];

    for(int i=1;i<=n;i++)
    {
        if(d[i]>l) { cout<<"NO"<<endl; return; }
        int x=l-d[i];
        if(x>=k) { pos=-k; continue; }
        pos=max(pos+1,-x);
        if(pos>x) { cout<<"NO"<<endl; return; }
    }
    cout<<"YES"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}