/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int GCD(int x, int y)
{
   if(y==0) return x;
   else return GCD(y, x%y);
}

void solve()
{
    int n, m, q;
    cin>>n>>m>>q;

    int g = GCD(n, m);
    int l = m/g;
    int r = n/g;

    while(q--)
    {
        int sx, sy, ex, ey;
        cin>>sx>>sy>>ex>>ey;

        if(sx==1) sy = (sy-1)/r;
        else sy = (sy-1)/l;

        if(ex==1) ey = (ey-1)/r;
        else ey = (ey-1)/l;

        if(sy==ey) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}