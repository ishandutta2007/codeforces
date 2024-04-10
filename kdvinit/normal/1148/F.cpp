/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int H = 64;

int lst_bit(int n)
{
    int cnt=0;
    while(n!=0) { n/=2; cnt++; }
    return cnt;
}

bool check_sign(int x, int y)
{
    if(x>0 && y>0) return true;
    if(x<0 && y<0) return true;
    return false;
}

int cnt_bits_in_and(int x, int y)
{
    int z = (x&y);
    int ans = 0;
    while(z!=0) { ans+=(z%2); z/=2; }
    return ans;
}

void solve()
{
    int n; cin>>n;

    int sum=0;
    vector<array<int, 2>> mask[H];

    for(int i=1; i<=n; i++)
    {
        int val, ms;
        cin>>val>>ms;
        sum+=val;

        int lb = lst_bit(ms);
        mask[lb].push_back({val, ms});
    }

    int p2[H];
    p2[1]=1;
    for(int i=2; i<H; i++) p2[i]=p2[i-1]*2;

    int ans = 0;
    for(int i=1; i<H; i++)
    {
        int cur = 0;
        for(auto x: mask[i])
        {
            int val = x[0];
            int ms = x[1];

            if(cnt_bits_in_and(ans, ms)%2==1) cur-=val;
            else cur+=val;
        }

        if(check_sign(sum, cur)) ans+=(p2[i]);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}