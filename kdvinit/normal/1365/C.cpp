/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int pa[n+1],freq[n]={0};

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        pa[x]=i;
    }

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        int y=pa[x]-i;
        if(y<0) y+=n;
        freq[y]++;
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,freq[i]);
    }

    cout<<ans<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	solve();
	return 0;
}