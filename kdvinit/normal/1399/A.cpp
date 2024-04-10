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

    int f[102]={0};
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        f[x]=1;
    }

    int cnt=0;
    for(int i=1;i<=100;i++)
    {
        if(f[i]==1 && f[i+1]==0) cnt++;
    }

    if(cnt>1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}