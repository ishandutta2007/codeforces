/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int n=s.size();

    int cnt0=0,cnt1=0,ans;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0') cnt0++;
        else cnt1++;
    }

    ans=min(cnt0,cnt1);
    if(ans%2==1) cout<<"DA"<<endl;
    else cout<<"NET"<<endl;
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