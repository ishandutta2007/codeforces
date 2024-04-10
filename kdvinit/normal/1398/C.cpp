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

    long long int a[n+1],sum[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        char x;
        cin>>x;
        a[i]=x-49;
    }

    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }

    long long int ans=0;
    sort(sum,sum+n+1);

    long long int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(sum[i]==sum[i-1]) cnt++;
        else
        {
            ans+=(((cnt)*(cnt-1))/2);
            cnt=1;
        }
    }
    ans+=(((cnt)*(cnt-1))/2);

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}