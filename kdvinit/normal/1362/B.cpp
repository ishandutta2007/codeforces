/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

int xr(int a,int b)
{
    int cntr=1,ans=a;
    while(b!=0)
    {
        if(b%2==1)
        {
            if(a%2==0) ans+=cntr;
            else ans-=cntr;
        }
        cntr*=2;
        b/=2;
        a/=2;
    }

    return ans;
}

void solve()
{
    int n;
    cin>>n;
    int a[n+1],freq[1024]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        freq[a[i]]=1;
    }

    int i;
    for(i=1;i<1024;i++)
    {
        int j;
        for(j=1;j<=n;j++)
        {
            if(freq[xr(a[j],i)]==0) break;
        }
        if(j>n) break;
    }

    if(i==1024) cout<<-1<<endl;
    else cout<<i<<endl;

    return;
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