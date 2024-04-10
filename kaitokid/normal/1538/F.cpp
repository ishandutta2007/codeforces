#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll p[15];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0]=1;
    for(int i=1;i<=9;i++)p[i]=p[i-1]*10;
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll res=0,cur=0;
        for(int i=9;i>=0;i--)
        {
            ll u=(a/p[i])%10;
            ll v=(b/p[i])%10;
            ll rs;
            if(v>=u)rs=v-u+cur*10;
            else rs= 10-u+v +(cur-1)*10;
            res+=rs;
            cur=rs;

        }
        cout<<res<<endl;
    }
    return 0;
}