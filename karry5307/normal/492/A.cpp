#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll comb[201],cnt;
inline ll calc(ll cnt)
{
    ll layer=0;
    while(cnt>=0)
    {
        cnt-=comb[++layer];
    }
    return layer-1;
}
int main()
{
    for(register int i=1;comb[i-1]<=10001;i++)
    {
        comb[i]=i*(i+1)/2;
    }
    cin>>cnt;
    cout<<calc(cnt)<<endl;
}