/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int sum=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        char x;
        cin>>x;

        if(x=='(') sum--;
        else sum++;

        ans=max(ans,sum);
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