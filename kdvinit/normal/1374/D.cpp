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

    long long int a[n+1],cnt=1,ans=0,val;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=k;
    }

    sort(a+1,a+n+1);

    if(a[n]==0) { cout<<0<<endl; return; }
    for(int i=2;i<=n;i++)
    {
        if(a[i]==0) continue;
        if(a[i]==a[i-1]) cnt++;
        else
        {
            if(cnt>ans)
            {
                ans=cnt;
                val=a[i-1];
                if(a[i-1]==0) val=a[i];
            }
            cnt=1;
        }
    }
    if(cnt>ans)
    {
        ans=cnt;
        val=a[n];
    }

    ans=k*(ans-1)+k-val+1;

    cout<<ans<<endl;
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