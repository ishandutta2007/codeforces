#include <iostream>

using namespace std;
typedef long long ll;
ll num[4000009][2],n,x,ans,u;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
cin>>n;
num[0][0]++;
u=0;
for(int i=1;i<=n;i++)
{
    cin>>x;
    u^=x;
    ans+=num[u][i%2];
    num[u][i%2]++;
}
cout<<ans;

    return 0;
}