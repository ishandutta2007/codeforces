#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int cntgrt=0,cntsml=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='>') cntgrt++;
        if(s[i]=='<') cntsml++;
    }

    if(cntgrt==0 || cntsml==0)
    {
        cout<<n<<endl;
        return;
    }

    int ans=0;

    for(int i=0;i<n;i++)
    {
        int x=i;
        int y=(i+1)%n;
        if(s[x]=='-' || s[y]=='-') ans++;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}