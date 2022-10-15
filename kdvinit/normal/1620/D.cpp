/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int c[3], m[3];
    for(int i=0; i<3; i++) c[i]=-1, m[i]=100;

    for(int i=1; i<=n; i++)
    {
        int x = a[i]/3, y = a[i]%3;
        c[y]=max(c[y], x);
        m[y]=min(m[y], x);
    }

    int ans;
    if(c[1]==-1 && c[2]==-1) { ans = c[0]; cout<<ans<<endl; return; }

    if(c[1]==-1)
    {
        ans = max(c[0], c[2])+1;
        cout<<ans<<endl;
        return;
    }

    if(c[2]==-1)
    {
        ans = max(c[0], c[1])+1;
        cout<<ans<<endl;
        return;
    }

    ans = max({c[0]-1, c[1], c[2]})+2;

    int tmp1 = ans+5;
    if(m[1]>0)
    {
        tmp1 = max({c[0], c[1]-1, c[2]})+2;
    }

    int tmp2 = ans+5;
    if(m[1]>0)
    {
        tmp2=0;
        for(int i=1; i<=n; i++)
        {
            if(a[i]%3==0)
            {
                if(a[i]>3) tmp2=max(tmp2, (a[i]-6)/3);
                else tmp2=max(tmp2, (int)1);
            }
            if(a[i]%3==1) tmp2 = max(tmp2, (a[i]-4)/3);
            if(a[i]%3==2) tmp2 = max(tmp2, (a[i]-2)/3);
        }
        tmp2+=3;
    }

    ans = min(ans, tmp1);
    ans = min(ans, tmp2);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}