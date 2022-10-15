/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin>>n;

    string a, b, c, ans;
    cin>>a>>b>>c;

    int p1=0, p2=0, p3=0;
    while(1)
    {
        if(p1==2*n || p2==2*n || p3==2*n) break;

        if(a[p1]==b[p2]) { ans+=a[p1]; p1++; p2++; }
        else if(a[p1]==c[p3]) { ans+=a[p1]; p1++; p3++; }
        else  { ans+=b[p2]; p2++; p3++; }
    }

    if(p1==2*n)
    {
        if(p2>=p3) while(p2!=2*n) ans+=b[p2++];
        else while(p3!=2*n) ans+=c[p3++];
    }
    else if(p2==2*n)
    {
        if(p1>=p3) while(p1!=2*n) ans+=a[p1++];
        else while(p3!=2*n) ans+=c[p3++];
    }
    else
    {
        if(p1>=p2) while(p1!=2*n) ans+=a[p1++];
        else while(p2!=2*n) ans+=b[p2++];
    }

    while(ans.size()!=3*n) ans+="0";
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}