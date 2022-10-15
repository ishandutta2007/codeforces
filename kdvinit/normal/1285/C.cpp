/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a,int b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

void solve()
{
    int x;
    cin>>x;

    int ans=x,a,b,y,z,w;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            y=i; z=(x/i);
            if(gcd(y,z)!=1) continue;
            w=max(y,z);
            if(w<=ans)
            {
                a=y; b=z;
            }
        }
    }

    cout<<a<<" "<<b<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}