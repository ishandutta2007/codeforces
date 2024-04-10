#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,a[10002],b[10002],ans;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;

    for(int i=1;i<=n;i++)
    {

        cin>>a[i]>>b[i];
        ll mn=max(a[i-1],b[i-1]),mx=min(a[i],b[i]);
        ans+=max(0LL,mx-mn+1);
        if(a[i]==b[i])ans--;
    }
    if(a[n]==b[n])ans++;
    cout<<ans;
    return 0;
}