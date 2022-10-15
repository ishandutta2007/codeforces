/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    string s;
    cin>>s;

    int n=s.size(),cnt1=0,cnt0=0,ans=0;
    for(int i=0;i<=n;i++)
    {
        if(s[i]=='1')
        {
            cnt1++;
            if(cnt1==1) continue;
            else ans+=cnt0;
            cnt0=0;
        }
        else
        {
            if(cnt1==0) continue;
            cnt0++;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}