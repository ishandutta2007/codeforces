#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n;
int main()
{

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll u=4;
        bool ans=false;
        while(!ans)
        {
            if(n%(u-1)==0){cout<<n/(u-1)<<endl;ans=true;break;}
            u*=2;
        }
    }

    return 0;
}