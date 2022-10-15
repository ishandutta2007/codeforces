/*
K.D. Vinit  |,,|
Don't Stalk My Code :)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int Sum(int x)
{
    int ans=0;
    while(x!=0)
    {
        ans+=x%10;
        x/=10;
    }
    return ans;
}

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

void solve()
{
    int n;
    cin>>n;

    int x = n;
    while(1)
    {
        int y=Sum(x);
        if(GCD(x,y)!=1) break;
        x++;
    }

    cout<<x<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}