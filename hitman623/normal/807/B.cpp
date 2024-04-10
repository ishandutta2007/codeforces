#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int check(long s, long p)
{
    long i=(s/50)%475,j;
    for(j=0;j<25;++j)
    {
        i = (i * 96 + 42)%475;
        if(26+i==p) return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long p,x,y,i,ans=1e9+5;
    cin>>p>>x>>y;
    for(i=x;i<200000;i+=50)
    if(i>=y && check(i,p)) {ans=min(ans,(i-x)/100+!!((i-x)%100));break;}
    for(i=x;i>=0;i-=50)
    if(i>=y && check(i,p)) {ans=0;break;}
    cout<<ans;
    return 0;
}