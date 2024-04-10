/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int eval(int a, int b)
{
    int b2 = a|b;
    int ans = b2-b;

    for(int i=22; i>=0; i--)
    {
        int cur = 1<<i;
        int bb = (cur&b);
        int ba = (cur&a);

        if(bb==0 && ba==0) continue;
        if(bb!=0 && ba!=0) continue;
        if(bb!=0 && ba==0)
        {
            a+=cur;
            if(a>=b) break;
        }
    }

    ans = min(ans, a-b);
    return ans;
}

void solve()
{
    int a, b;
    cin>>a>>b;

    int ans = b-a;
    for(int i=a; i<b; i++)
    {
        int tmp = (i-a+1) + eval(i, b);
        ans = min(ans, tmp);
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