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

    long long int a[n+1],mn=1e9,mx;
    mx=-mn;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }

    if(mn!=0)
    {
        k--;
        for(int i=1;i<=n;i++) a[i]=mx-a[i];
    }

    if(k%2==0)
    {
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    else
    {
        mx-=mn;
        for(int i=1;i<=n;i++) a[i]=mx-a[i];
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}