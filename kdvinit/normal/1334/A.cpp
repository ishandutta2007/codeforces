/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n,flag=1;
    cin>>n;

    int p[n+1],c[n+1],d=0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>c[i];
        if(p[i]-c[i]<d) flag=0;
        d=p[i]-c[i];
        if(i==1) continue;
        if(p[i-1]>p[i]) flag=0;
        if(c[i-1]>c[i]) flag=0;
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}