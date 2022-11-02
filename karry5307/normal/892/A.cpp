#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll cnt,cap[100001],num,tot;
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num;
        tot+=num;
    }
    for(register int i=0;i<cnt;i++)
    {
        cin>>cap[i];
    }
    sort(cap,cap+cnt,greater<ll>());
    cap[0]+cap[1]>=tot?cout<<"YES"<<endl:cout<<"NO"<<endl;
}