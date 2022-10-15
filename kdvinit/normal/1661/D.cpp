/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int cil(int x, int y)
{
    int ans = (x+y-1)/y;
    return ans;
}

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int sum=0;
    int pstp[n+1]={0};
    int con=0;
    int ans=0;

    for(int i=n; i>=1; i--)
    {
        sum -= con;
        con -= pstp[i];
        a[i] -= sum;

        int dec = min(k, i);
        int cnt = 0;
        if(a[i]>0) cnt=cil(a[i], dec);
        ans += cnt;

        //cout<<i<<" -> "<<cnt<<" "<<sum<<" "<<con<<endl;

        sum += (dec*cnt);
        con += cnt;
        int si = max((int)0, i-k);
        pstp[si] += cnt;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}