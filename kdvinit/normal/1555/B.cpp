/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int W, H, x1, y1, x2, y2, w, h;
    cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;

    int w2 = x2-x1;
    int h2 = y2-y1;

    if( (w+w2)>W && (h+h2)>H) { cout<<-1<<endl; return; }

    int ans = H+W, tmp;

    if( (w+w2)<=W )
    {
        if(x1>=w) { cout<<0<<endl; return; }
        if(x2+w<=W) { cout<<0<<endl; return; }
        tmp = w - (W-x2);   ans=min(ans, tmp);
        tmp = (w-x1);   ans=min(ans, tmp);
    }

    if( (h+h2)<=H )
    {
        if(y1>=h) { cout<<0<<endl; return; }
        if(y2+h<=H) { cout<<0<<endl; return; }
        tmp = h - (H-y2);   ans=min(ans, tmp);
        tmp = (h-y1);   ans=min(ans, tmp);
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