/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int eval(int a[], int n, int mxh)
{
    int odd=0, even=0;

    for(int i=1; i<=n; i++)
    {
        int lft = mxh-a[i];
        if(lft%2==1) odd++;
        even+=(lft/2);
    }

    if(even>odd)
    {
        int dif = even-odd;
        int tr = dif/3;

        even-=tr;
        odd+=(2*tr);

        if(dif%3==2)
        {
            even--;
            odd+=2;
        }
    }

    int ans = 0;
    if(odd>even) ans = (2*odd) - 1;
    else ans = 2*(even);

    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int mx=-1;
    for(int i=1; i<=n; i++) mx = max(mx, a[i]);

    int ans1 = eval(a, n, mx);
    int ans2 = eval(a, n, mx+1);
    int ans = min(ans1, ans2);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}