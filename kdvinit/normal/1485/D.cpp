/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int x,int y)
{
    if(x%y==0) return y;
    else return gcd(y, x%y);
}

int lcm(int x,int y)
{
    int ans=(x*y);
    ans/=gcd(x,y);
    return ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    int val=6;
    for(int i=4;i<=16;i++)
    {
        val=lcm(val,i);
    }

    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;

            if((i+j)%2==0) cout<<val<<" ";
            else cout<<(val+pow(x,4))<<" ";
        }
        cout<<endl;
    }



}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}