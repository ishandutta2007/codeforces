#include <iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef long double ld;

ld a,b,c,d;

ld MIN(ld x,ld y,ld k)
{
    ld ans=x*y;
    ans=min(ans,(x-k)*(y+k));
    ans=min(ans,(x+k)*(y-k));
    ans=min(ans,(x+k)*(y+k));
    ans=min(ans,(x-k)*(y-k));
    return ans;
}

ld MAX(ld x,ld y,ld k)
{
    ld ans=x*y;
    ans=max(ans,(x-k)*(y+k));
    ans=max(ans,(x+k)*(y-k));
    ans=max(ans,(x+k)*(y+k));
    ans=max(ans,(x-k)*(y-k));
    return ans;
}

bool check(ld k)
{
    if(MIN(a,d,k)-MAX(b,c,k)<=0 && MAX(a,d,k)-MIN(b,c,k)>=0)
        return true;
    return false;
}

int main()
{
    cin>>a>>b>>c>>d;
    ld l=0,r=1000000000;
    for(int i=0;i<100;i++)
    {
        ld mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid;
    }
    cout<<fixed<<setprecision(10)<<l<<endl;
}