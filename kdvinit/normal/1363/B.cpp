#include <iostream>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    int sum[n+1]={0},ans=n,temp0,temp1;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1];
        if(s[i-1]=='1') sum[i]++;
    }
    for(int j=1;j<=n;j++)
    {
        temp0=n-(j)-sum[n]+(sum[j])*2;
        temp1=n-temp0;
        ans=min(ans,temp0);
        ans=min(ans,temp1);
    }
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