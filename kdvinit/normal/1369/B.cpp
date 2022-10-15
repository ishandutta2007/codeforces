/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int a[n+2]={0};
    a[n+1]=1;
    for(int i=1;i<=n;i++)
    {
        char x;
        cin>>x;
        if(x=='1') a[i]=1;
    }

    int f1,l0;
    for(int i=1;i<=n+1;i++)
    {
        if(a[i]==1) { f1=i-1; break; }
    }

    for(int i=n;i>=0;i--)
    {
        if(a[i]==0) { l0=n-i; break; }
    }

    //cout<<f1<<" "<<l0<<endl;

    if(f1+l0==n)
    {
        for(int i=1;i<=n;i++) cout<<a[i];
        cout<<endl;
    }
    else
    {
        for(int i=1;i<=f1+1;i++) cout<<0;
        for(int i=1;i<=l0;i++) cout<<1;
        cout<<endl;
    }
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