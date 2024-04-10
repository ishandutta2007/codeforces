#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
ll ans=1,a,t;
cin>>t;
while(t--)
{
    cin>>a;
    ans=1;
    for(int i=0;i<32;i++)
        if(a&(1<<i))ans*=2;
    cout<<ans<<endl;
}
    return 0;
}