/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    string s;
    cin>>s;

    long long int n=s.size();
    long long int sum=0,ans=n,val=0;

    for(long long int i=1;i<=n;i++)
    {
        if(s[i-1]=='+') sum++;
        else sum--;

        if(val>sum) { ans+=i; val=sum; }
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