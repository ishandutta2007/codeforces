#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,num[1005],maxn=-1,tot;
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num[i];
        maxn=max(maxn,num[i]);
    }
    for(register int i=0;i<cnt;i++)
    {
        tot+=(maxn-num[i]);
    }
    cout<<tot;
}