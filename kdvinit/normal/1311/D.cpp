/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mx=1e4;

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;

    int A,B,C,ans=1e10;
    for(int i=1;i<=2*a;i++)
    {
        int x=i;
        for(int j=1;i*j<=3*b;j++)
        {
            int y=j*x;
            int xx=c/y;
            if(xx==0) xx++;
            int z1=xx*y;
            int z2=(xx+1)*y;
            int d1=abs(z1-c);
            int d2=abs(z2-c);
            int z=z1;
            if(d2<d1) z=z2;
            int tmp=abs(a-x)+abs(b-y)+abs(c-z);
            if(tmp<=ans)
            {
                ans=tmp;
                A=x;
                B=y;
                C=z;
            }
        }
    }
    cout<<ans<<endl;
    cout<<A<<" "<<B<<" "<<C<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}