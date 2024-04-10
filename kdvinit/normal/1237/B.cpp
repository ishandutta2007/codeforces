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

    int a[n+1],b[n+1],pos[n+1];
    for(int i=1;i<=n;i++) cin>>a[n+1-i];
    for(int i=1;i<=n;i++) cin>>b[n+1-i];
    for(int i=1;i<=n;i++) pos[a[i]]=i;

    int ans=0,cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(pos[b[i]]>=cnt) cnt=pos[b[i]]+1;
        else ans++;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	while(t--) solve();
	return 0;
}