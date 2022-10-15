/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int p,f,cnts,cntw,s,w,a,cnta,b,cntb,sum,sum2,ans,m1,m2;
    cin>>p>>f>>cnts>>cntw>>s>>w;

    sum=p+f;

    if(s<w) { a=s; cnta=cnts; b=w, cntb=cntw; }
    else { a=w; cnta=cntw; b=s, cntb=cnts; }
    
    m1=p/a;
    m2=f/a;

    if(m1+m2<=cnta)
    {
        ans=m1+m2;
    }
    else
    {
        ans=0;
        int tp,tf,temp;
        for(int i=0;i<=cnta;i++)
        {
            tp=p-i*a;
            tf=f-(cnta-i)*a;
            if(tp<0 || tf<0) continue;
            temp=tp/b;
            temp+=(tf/b);
            if(temp>cntb) temp=cntb;
            ans=max(ans,cnta+temp);
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}