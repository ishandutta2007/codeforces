/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int n,cnt2=0,cnt3=0,ans=0;
    cin>>n;

    if(n==1) { cout<<0<<endl; return; }
    while(n%2==0)
    {
        cnt2++;
        n/=2;
    }
    while(n%3==0)
    {
        cnt3++;
        n/=3;
    }

    if(n!=1 || cnt3==0 || cnt2>cnt3) { cout<<-1<<endl; return; }
    ans=cnt3-cnt2;
    ans+=(cnt3);
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