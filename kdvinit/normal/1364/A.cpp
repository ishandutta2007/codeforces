/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n,x,temp=0,ans1=0,ans2=0,cntr=0;
    cin>>n>>x;

    for(int i=1;i<=n;i++)
    {
        int y;
        cin>>y;
        y%=x;
        temp+=y;
        temp%=x;
        if(temp!=0)
        {
            if(cntr==0) ans2=i;
            ans1=i;
            cntr++;
        }
    }

    if(ans1==0) cout<<-1<<endl;
    else cout<<max(max(ans1,n-ans1),max(ans2,n-ans2))<<endl;
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