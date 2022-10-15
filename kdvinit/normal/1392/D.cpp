/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int n;
    cin>>n;

    char a[n+1];
    for(long long int i=1;i<=n;i++) cin>>a[i];
    long long int ans=0,strt=1,nd=n;

    while(strt!=n+1 && a[strt]==a[1]) strt++;
    if(strt==n+1) { cout<<(n+2)/3<<endl; return; }

    while(a[nd]==a[n]) nd--;

    long long int cnt=1;
    for(long long int i=strt+1;i<=nd;i++)
    {
        if(a[i]==a[i-1]) cnt++;
        else
        {
            ans+=(cnt/3);
            cnt=1;
        }
    }
    ans+=(cnt/3);

    strt--;
    nd=n-nd;

    if(a[1]==a[n]) ans+=((strt+nd)/3);
    else
    {
        ans+=(strt/3);
        ans+=(nd/3);
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