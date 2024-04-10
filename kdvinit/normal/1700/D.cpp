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
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans=a[1];

    int sum=0;
    for(int i=1; i<=n; i++)
    {
        sum+=a[i];
        int tmp = cil(sum, i);
        ans=max(ans, tmp);
    }

    int q; cin>>q;
    while(q--)
    {
        int x; cin>>x;
        if(x<ans) { cout<<-1<<endl; continue; }

        int cur = cil(sum, x);
        cout<<cur<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}