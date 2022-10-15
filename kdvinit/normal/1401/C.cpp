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

    long long int a[n+1],b[n+1],mn,poss[n+1]={0};
    for(int i=1;i<=n;i++) { cin>>a[i]; b[i]=a[i]; }
    sort(b+1,b+n+1);
    mn=b[1];

    for(int i=1;i<=n;i++)
    {
        if(a[i]%mn==0) poss[i]=1;
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i] && poss[i]==0) { cout<<"NO"<<endl; return; }
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